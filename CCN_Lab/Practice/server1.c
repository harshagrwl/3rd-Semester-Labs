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
char s[80],f[80];
struct sockaddr_in servaddr,cliaddr;
int listenfd , connfd;
uint clilen;
listenfd = socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(serv_port);
bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
listen(listenfd,1);
clilen = sizeof(cliaddr);
connfd = accept(listenfd,(struct sockaddr*)&cliaddr,&clilen);

printf("client connected\n");
recv(connfd,f,sizeof(f),0);
printf("%s",f);
bzero(f,80);
printf("type text:");
fgets(s,sizeof(s),stdin);
send(connfd,s,sizeof(s),0);
close(listenfd);

}