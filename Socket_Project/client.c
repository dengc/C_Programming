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

int main(int argc, char *argv[]){

	//some attributes for a socket as a client
	int sockfd, portno;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	//connect to TCP port number of edge server
	portno = atoi("23662");

 	//new socket
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	server = gethostbyname("127.0.0.1");
	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = PF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	//connect()
	if(connect(sockfd, &serv_addr, sizeof(serv_addr))<0){
		printf("connecting!\n");
	}
	//Booting Up
	else{
		printf("The client is up and running.\n");
	}

	int count =0;
	char * buffer = 0;
	char send_data[256];
	long length;

	//open and read a file
	FILE * f = fopen( argv[1] , "rb");
	if (f){
		while (fscanf(f, "%s", send_data)!=EOF){
		    count++;
		}
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = malloc (length);
		if (buffer){
			//put the file content in buffer
			fread (buffer, 1, length, f);
		}
		buffer[length] = '\0';
		fclose (f);
	}
	//send lines to edge server
	send(sockfd,buffer,strlen(buffer), 0);

	//send the number of lines of the content
	char snum[100];
	snprintf(snum, 100, "%d", count);
    send(sockfd,snum,strlen(snum), 0);
	read(sockfd, buffer, 255);
	bzero(buffer,256);

	//After sending all lines to the edge server
	printf("The client has successfully finished sending %d lines to the edge server.\n", count);

	printf("The client has successfully finished receiving all computation results from the edge server.\n");
	printf("The final computation results are:\n");

	//receiving all computation results from the edge server and they are sorted
	for(int i=0; i<count; i++){
		read(sockfd, buffer, 255);
		char *newBuf;
		newBuf = strtok(buffer,"\n");
		newBuf = strtok(newBuf,"=");
		newBuf = strtok(NULL,"=");
		newBuf = strtok(newBuf," ");
		printf("%s\n",newBuf );
		bzero(buffer,256);
		bzero(newBuf,256);
	}
	return 0;
}
