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
	uint clilen;
	struct sockaddr_in servaddr, cliaddr;
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	int ans;
	bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

	listen(listenfd,1);

	clilen = sizeof(cliaddr);
	int connection = accept(listenfd,(struct sockaddr*)&cliaddr,&clilen);
	printf("\nClient Connected\n");

	while(strcmp(buffer,"bye")!=0){
	ans = read(connection,buffer,50);
	printf("Client:	%s",buffer);
	printf("\nServer:	");
	fgets(hello,sizeof(hello),stdin);
	send(connection,hello,strlen(hello),0);
}
	close(listenfd);
}