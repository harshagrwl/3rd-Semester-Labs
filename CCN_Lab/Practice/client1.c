#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#define serv_port 5576

int main(int argc,char **argv)
{
ssize_t n;
char recv[80],filename[80];
struct sockaddr_in servaddr;
int sockfd;
sockfd = socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(serv_port);
inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

//bzero(filename,80);
printf("type text: ");
fgets(filename,sizeof(filename),stdin);
send(sockfd,filename,sizeof(filename),0);
bzero(filename,80);
read(sockfd,filename,80);
printf("%s",filename);
close(sockfd);
}