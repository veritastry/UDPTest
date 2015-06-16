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

#define PORT 8554 
#define MAXDATASIZE 102400
//#define IP  "10.5.5.101"
#define IP  "10.5.5.9"

int main(int argc, char *argv[])
{
int fd1, numbytes;
char recvbuf[MAXDATASIZE];
struct sockaddr_in server,self,rep;
if ((fd1=socket(AF_INET, SOCK_DGRAM, 0))==-1){
printf("socket() error\n");
exit(1);
}


bzero(&self,sizeof(self));
self.sin_family = AF_INET;
self.sin_port = htons(PORT);
int server_ip1;
inet_pton(AF_INET, IP, (void*) &server_ip1);
server.sin_addr.s_addr = server_ip1;
socklen_t len;
len=sizeof(struct sockaddr_in);
memset(recvbuf,0,sizeof(recvbuf));
bind(fd1,(struct sockaddr*)&self,sizeof(self));
recvfrom(fd1,recvbuf,MAXDATASIZE,0,(struct sockaddr * ) &rep,&len);
printf("A server give me:%s\n",recvbuf );

return 0;
}
