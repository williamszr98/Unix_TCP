#include <stdlib.h>

#include <stdio.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <string.h>

#include <arpa/inet.h>

#define MAXLINE 4096 /*max text line length*/
#include <bits/stdc++.h> 

//#define SERV_PORT 10010 /*port*/

int

main(int argc, char **argv)

{

int sockfd;

struct sockaddr_in servaddr;

char sendline[MAXLINE], recvline[MAXLINE];

alarm(300); // to terminate after 300 seconds

//basic check of the arguments

//additional checks can be inserted

// ******Change here********
if (argc != 4) { // was 3

perror("Usage: TCPClient <Server IP> <Server Port> <Command file>");

exit(1);

}

//Create a socket for the client

//If sockfd<0 there was an error in the creation of the socket

if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) <0) {

perror("Problem in creating the socket");

exit(2);

}

//Creation of the socket

memset(&servaddr, 0, sizeof(servaddr));

servaddr.sin_family = AF_INET;

servaddr.sin_addr.s_addr= inet_addr(argv[1]);

servaddr.sin_port = htons(atoi(argv[2])); // Convert char * to int (htons required integer argument)

//servaddr.sin_port = htons(SERV_PORT); //convert to big-endian order

//Connection of the client to the socket

if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr))<0) {

perror("Problem in connecting to the server");

exit(3);

}

while (fgets(sendline, MAXLINE, stdin) != NULL) {

const char* filename;
for(int i=3; i< argc;i++){
//printf("%s",argv[i]);
filename = argv[i];
}

// This runs the command from the 3rd argument but only in client
//system(filename);
printf("\n");//New line
send(sockfd, filename, strlen(filename),0);
printf("\n");//New line

//send(sockfd, sendline, strlen(sendline), 0);

if (recv(sockfd, recvline, MAXLINE,0) == 0){

//error: server terminated prematurely

perror("The server terminated prematurely");

exit(4);

}

printf("%s", "String received from the server: ");


fputs(recvline, stdout);




printf("\n");//New line

}

exit(0);

}