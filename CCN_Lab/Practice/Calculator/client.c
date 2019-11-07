#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

#define PORT 5576

main(int argc, char** argv){
	struct sockaddr_in sa;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&sa,sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(PORT);
	inet_pton(AF_INET,argv[1], &sa.sin_addr);
	connect(sockfd,(struct sockaddr*)&sa,sizeof(sa));

	int buffer[1024];
	int n, n1, n2, choice, ans;

	bzero(buffer,256);
	n = read(sockfd,buffer, 255);
	printf("%s\n",buffer);
	scanf("%d",&n1);
	write(sockfd,&n1,sizeof(int));

	bzero(buffer,256);
	n = read(sockfd,buffer, 255);
	printf("%s\n",buffer);
	scanf("%d",&n2);
	write(sockfd,&n2,sizeof(int));

	bzero(buffer,256);
	n = read(sockfd,buffer, 256);
	printf("%s\n",buffer);
	scanf("%d",&choice);
	write(sockfd,&choice,sizeof(int));

	read(sockfd,&ans,sizeof(int));
	printf("The answer is: %d\n",ans);

	close(sockfd);
}