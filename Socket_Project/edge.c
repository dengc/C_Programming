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

//3 helper methods
char *sendUDP(char * buf);
char *sendOR(char * src);
char *sendAND(char * src);

int main(){

	//some attributes for a socket as a server
	int sockfd, newsockfd, portno, clilen;
	char buffer[256];
	char bufferCount[100];
	struct sockaddr_in serv_addr, cli_addr;

	//new socket
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	bzero((char *)&serv_addr, sizeof(serv_addr));

	//TCP port number
	portno = atoi("23662");
	serv_addr.sin_family = PF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	//bind()
	if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){
		printf("binding");
	}
	//booting up
	else{
		printf("The edge server is up and running.\n");
	}

	//listen()
	listen(sockfd, 100);
	clilen = sizeof(cli_addr);

	//accept()
	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	bzero(buffer, 256);

	//receive all lines
	read(newsockfd, buffer, 255);
	//receive the number of lines
	read(newsockfd, bufferCount, 100);

	//After receiving all lines from the client
	printf("The edge server has received %s lines from the client using TCP over port 23662\n", bufferCount);

	//to see the numbers of ORs and ANDs
	int count_or = 0;
	int count_and = 0;
	char src[256];
	char dest[256];
	char bufferSub[256];
	strcpy(bufferSub,buffer);
	memset(dest, '\0', sizeof(dest));
	char *token;
	char *search = "\n";
	token = strtok(bufferSub,search);
	strcpy(src, token);
	strncpy(dest, src, 1);
	if(strcmp(dest, "o")==0){
		count_or ++;
	}
	else{
		count_and ++;
	}
	while (token != NULL){
		memset(dest, '\0', sizeof(dest));
	    token = strtok (NULL,search);
	    if(token){
	    	strcpy(src, token);
			strncpy(dest, src, 1);
		    if(strcmp(dest, "o")==0){
				count_or ++;
			}
			else{
				count_and ++;
			}
		}
 	}

	//send the numbers of ORs and ANDs to Backend-Servers
 	char num_or[100];
	char num_and[100];
	snprintf(num_or, 100, "%d", count_or);
	snprintf(num_and, 100, "%d", count_and);
	sendOR(num_or);
	sendAND(num_and);
	send(newsockfd, "", 255,0);
	printf("The edge server has successfully sent %d lines to Backend-Server OR.\n", count_or);
	printf("The edge server has successfully sent %d lines to Backend-Server AND.\n", count_and);

	//Start receiving the computation results from “Backend-Server OR” and “Backend-Server AND” using UDP
	printf("The edge server start receiving the computation results from Backend-Server OR and Backend-Server AND using UDP port 24662.\n");
	printf("The computation results are:\n");

	//send computation lines and get results, send them to the client
	token = strtok(buffer,search);
	send(newsockfd, sendUDP(token), 255,0);
	while (token != NULL){
	    token = strtok (NULL,search);
	    if(token !=NULL){
	    	send(newsockfd, sendUDP(token), 255,0);
		}
 	}

	//After receiving all computation results from “Backend-Server OR” and “Backend-Server AND”
	printf("The edge server has successfully finished receiving all computation results from the Backend-Server OR and Backend-Server AND.\n");

	printf("The edge server has successfully finished sending all computation results to the client.\n");

	return 0;

}

//send lines to Backend-Servers
char *sendUDP(char * buf){
	char src[256];
	char dest[256];
	memset(dest, '\0', sizeof(dest));
	strcpy(src, buf);
	strncpy(dest, src, 1);

	//to check if it is "OR" or "AND"
	if(strcmp(dest, "o")==0){
		return sendOR(src);
	}
	else{
		return sendAND(src);
	}
}

//send each OR computation” line to the Backend-Server OR, and return the result
char *sendOR(char * src){
	int sock, length;
	struct sockaddr_in server, from;
	struct hostent *hp;
	sock = socket(PF_INET, SOCK_DGRAM, 0);
	server.sin_family = PF_INET;
	hp = gethostbyname("127.0.0.1");
	bcopy((char *)hp->h_addr, (char *)&server.sin_addr, hp->h_length);
	server.sin_port = htons(atoi("21662"));
	length = sizeof(struct sockaddr_in);

	sendto(sock, src, strlen(src), 0, &server, length);

	char newToken[100];

	//receive computation results from server_or
	recvfrom(sock, newToken, 256, 0, &from, &length);

	//Upon receiving one computation result from “Backend-Server OR”
	printf("%s", newToken);

	return newToken;
}

//send each “AND computation” line to the Backend-Server AND, and return the result
char *sendAND(char * src){
	int sock, length;
	struct sockaddr_in server, from;
	struct hostent *hp;
	sock = socket(PF_INET, SOCK_DGRAM, 0);
	server.sin_family = PF_INET;
	hp = gethostbyname("127.0.0.1");
	bcopy((char *)hp->h_addr, (char *)&server.sin_addr, hp->h_length);
	server.sin_port = htons(atoi("22662"));
	length = sizeof(struct sockaddr_in);

	sendto(sock, src, strlen(src), 0, &server, length);

	char newToken[100];

	//receive computation results from server_and
	recvfrom(sock, newToken, 256, 0, &from, &length);

	//Upon receiving one computation result from “Backend-Server AND”
	printf("%s", newToken);

	return newToken;
}
