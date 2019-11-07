#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

#define PORT 5576

main(int argc, char** argv){
	struct sockaddr_in sa, ca;
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&sa,sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(PORT);
	bind(listenfd,(struct sockaddr*)&sa,sizeof(sa));
	listen(listenfd,1);
	uint cl = sizeof(ca);
	int connectfd = accept(listenfd,(struct sockaddr*)&ca,&cl);
	printf("\n Client Connected");

	int n,n1,n2,ans, choice;

		n = write(connectfd,"EnterNum1 : ",strlen("EnterNum1") );
		read(connectfd, &n1,sizeof(int));
		printf("Number 1 is: %d",n1);

		n = write(connectfd,"EnterNum2 : ",strlen("EnterNum2") );
		read(connectfd, &n2,sizeof(int));
		printf("Number 2 is: %d",n2);

		n = write(connectfd,"Enter your choice :\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n ",strlen("Enter your choice :\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n") );
		read(connectfd, &choice,sizeof(int));
		printf("Choice is: %d",choice);

		switch(choice)
     {
     	case 1:
     		ans = n1 + n2;
     		break;
     	case 2:
     		ans = n1 -n2;
     		break;
     	case 3:
     		ans = n1*n2;
     		break;
     	case 4:
     		ans = n1/n2;
     		break;
     }
     
     write(connectfd , &ans , sizeof(int));
	
	close(listenfd);
}