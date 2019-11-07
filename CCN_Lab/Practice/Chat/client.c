#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

#define SERV_PORT 5576

main(int argc, char** argv){
	ssize_t n;
	FILE *fp;
	char s[50],f[50];
	char buffer[50] = {0};
	char hello[50];
	int val;
	struct sockaddr_in servaddr;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);


	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

	while(strcmp(buffer,"bye")!=0){
	printf("Client:	");
	fgets(hello,sizeof(hello),stdin);
	send(sockfd,hello,strlen(hello),0);
	val = read(sockfd,buffer,50);
	printf("Server:	%s",buffer);
}
	close(sockfd);
}