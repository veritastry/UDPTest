//client.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORT 50126
#define MAXDATASIZE 100

int main(int argc, char *argv[])
{
int fd1, numbytes;
char recvbuf[MAXDATASIZE];
char sendbuf[MAXDATASIZE];
struct sockaddr_in server,self,rep;
if ((fd1=socket(AF_INET, SOCK_DGRAM, 0))==-1){
printf("socket() error\n");
exit(1);
}

int server_ip1;


bzero(&self,sizeof(self));
self.sin_family = AF_INET;
self.sin_port = htons(PORT);
inet_pton(AF_INET, "192.168.11.215", (void*) &server_ip1);
        server.sin_addr.s_addr = server_ip1;

bind(fd1,(struct sockaddr*)&self,sizeof(self));

int server_ip;
bzero(&server,sizeof(server));
server.sin_family = AF_INET;
server.sin_port = htons(PORT);
inet_pton(AF_INET, "192.168.11.215", (void*) &server_ip);
        server.sin_addr.s_addr = server_ip;

        socklen_t len;
         len=sizeof(struct sockaddr_in);
 printf("input message:");
         fgets(sendbuf,40,stdin);
sendto(fd1,sendbuf,strlen(sendbuf),0,(struct sockaddr *)&server,len);
printf("send already\n");
int fd2=socket(AF_INET,SOCK_DGRAM,0);
int i=bind(fd2,(struct sockaddr*)&self,sizeof(self));
printf("%d\n",i);
memset(sendbuf,0,sizeof(sendbuf));
fgets(sendbuf,sizeof(sendbuf),stdin);
sendto(fd2,sendbuf,strlen(sendbuf),0,(struct sockaddr *)&server,len);
memset(recvbuf,0,sizeof(recvbuf));
recvfrom(fd1,recvbuf,strlen(sendbuf),0,(struct sockaddr * ) &rep,&len);
printf("A server give me:%s\n",recvbuf );
recvfrom(fd2,recvbuf,strlen(sendbuf),0,(struct sockaddr * ) &rep,&len);
printf("fd2 server give me:%s\n",recvbuf);

return 0;
}
