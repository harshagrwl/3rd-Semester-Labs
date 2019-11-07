#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 5576

main(int argc, char** argv){
	struct sockaddr_in servaddr, cliaddr;
	int listenfd = socket(AF_INET, SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	listen(listenfd,1);
	uint clilen = sizeof(cliaddr);
	int connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen);
	printf("CLient Connected\n");

	FILE *fp;
	fp = fopen("abc_modified.txt", "a");
	int words;
	int ch = 0;
	char buffer[1024];
	read(connfd, &words, sizeof(int));
	while(ch!= words){
		read(connfd, buffer, 255);
		fprintf(fp, "%s ", buffer);
		ch++;
	}
	printf("File is received\n");

	close(listenfd);
}