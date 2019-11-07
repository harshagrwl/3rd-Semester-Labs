#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<ctype.h>

#define PORT 5576

main(int argc, char** argv){
	struct sockaddr_in servaddr;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	printf("Connection with server establisher\n");

	FILE *f;
	int words = 0;
	char c, buffer[1024];
	bzero(buffer, 255);
	f = fopen("abc.txt", "r");
	while(c = getc(f)!=EOF){
		fscanf(f, "%s", buffer);
		
		if(isspace(c) || c == "\t"){
			words++;
		}
	}
	write(sockfd, &words, sizeof(int));
	rewind(f);

	char ch;
	while(ch!= EOF){
		fscanf(f, "%s", buffer);
		write(sockfd, buffer, 255);
		ch = fgetc(f);
	}
	printf("THe file has been sent\n");
	close(sockfd);
}