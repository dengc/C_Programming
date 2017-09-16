#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main(){

	//some attributes for a socket as a server
	int sock, length, fromlen;
	struct sockaddr_in server;
	struct sockaddr_in from;
	char buf[100];

	//new socket
	sock = socket(PF_INET, SOCK_DGRAM, 0);
	length = sizeof(server);
	bzero(&server, length);
	server.sin_family = PF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi("22662"));

	//bind()
	if(bind(sock, (struct sockaddr *)&server, length)<0){
		printf("binding");
	}
	//booting up
	else{
		printf("The Server AND is up and running using UDP on port 22662.\n");
		printf("The Server AND start receiving lines from the edge server for AND computation. The computation results are:\n");
	}

	fromlen = sizeof(struct sockaddr_in);

	//receive the number of lines from edge
	recvfrom(sock, buf, 100, 0, (struct sockaddr *)&from, &fromlen);
	int bufCount = atoi(buf);
	sendto(sock, "", 17, 0, (struct sockaddr *)&from, fromlen);

	//String array for storing content of each line
	char bufArray[bufCount][100];

	for(int count =0; count<bufCount; count++){

		//receive lines' content from edge
		recvfrom(sock, buf, 100, 0, (struct sockaddr *)&from, &fromlen);
		strcpy(bufArray[count], buf);
		bzero(buf,100);

		char *token1;
		char *token2;
		char *search = ",";
		token1 = strtok(bufArray[count],search);

		//first binary
		token1 = strtok (NULL,search);
		//second binary
		token2 = strtok (NULL,search);

		//the maxLength of the two binary
		int maxLength = strlen(token1);
		if(maxLength < strlen(token2)){
			maxLength = strlen(token2);
		}

		char new_token1[100];
		char new_token2[100];

		//padding 0s for the shorter one to make both in same length
		if(strlen(token1)<maxLength){
			for(int i =0; i<maxLength - strlen(token1); i++){
				strcpy(&new_token1[i],"0");
			}
			for(int i = maxLength - strlen(token1); i<maxLength; i++){
				strcpy(&new_token1[i],&token1[i-maxLength+strlen(token1)]);
			}
		}
		else{
			strcpy(new_token1,token1);
		}
		if(strlen(token2)<maxLength){
			for(int i =0; i<maxLength - strlen(token2); i++){
				strcpy(&new_token2[i],"0");
			}
			for(int i = maxLength - strlen(token2); i<maxLength; i++){
				strcpy(&new_token2[i],&token2[i-maxLength+strlen(token2)]);
			}
		}
		else{
			strcpy(new_token2,token2);
		}

		//Do OR Operation
		char tokenChar[100];
		for(int j =0; j<maxLength; j++){
			char newc1 = new_token1[j];
			char newc2 = new_token2[j];

			//both 1s, 1; else, 0
			if(newc1 == '1' && newc2 =='1'){
				strcpy(&tokenChar[j],"1");
			}
			else{
				strcpy(&tokenChar[j],"0");
			}
		}

		//avoid 0 appears before 1
		int tokenTotal = atoi(tokenChar);
		char tokenTotalChar[10];
		snprintf(tokenTotalChar, 10, "%d", tokenTotal);

		//make each result line a string
		char token[100];
		strcpy(token, token1);
		strcat(token, " and ");
		strcat(token, token2);
		strcat(token, " = ");
		strcat(token, tokenTotalChar);
		strcat(token, "\n");

		//send the computation results to edge server
		sendto(sock, token, 100, 0, (struct sockaddr *)&from, fromlen);
		printf("%s",token );
		bzero(token,100);
	}

	//After receiving all lines and finishing all “AND computation”
	printf("The Server AND has successfully received %d lines from the edge server and finished all AND computations.\n", bufCount);

	//After sending all computation results to the edge server
	printf("The Server AND has successfully finished sending all computation results to the edge server\n");

	return 0;
}
