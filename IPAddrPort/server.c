//service.c
//http://www.cnblogs.com/ymy124/archive/2012/04/22/2465599.html

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define  SERADDR "127.0.0.1"
#define IP "10.5.5.9"
int main(int ar, char**argv) {
        int fd1, fd2;
        char *s;
        char ss[20];
        char port[7];
        int server_ip;
        char buf[1024];
        int len=sizeof(struct sockaddr);
        int sin_size = sizeof(struct sockaddr_in);
        struct sockaddr_in local_addr,other,other1;
        if (-1 == (fd1 = socket(AF_INET, SOCK_DGRAM, 0))) {
                perror("fail to socket\n");
                exit(0);
        }
        memset(buf,0,1024);
        memset(&local_addr,0,sizeof(struct sockaddr));
        local_addr.sin_family = AF_INET;
        local_addr.sin_port = htons(50126);

        inet_pton(AF_INET, IP, (void*) &server_ip);
        local_addr.sin_addr.s_addr = server_ip;


        if (bind(fd1, (struct sockaddr*) &local_addr, sizeof(struct sockaddr))
                        < 0) {
                fprintf(stderr, "error:bind() error!\n");
		exit(-1);
        }


        recvfrom(fd1,buf,1023,0,(struct sockaddr*)&other,&len);
        in_port_t temport=ntohs(other.sin_port);
        sprintf(port,"%u",temport);
        printf("A,port =%s\n",port);
        printf("A ,client give me:%s\n",buf);
        memset(buf,0,sizeof(buf));

        recvfrom(fd1,buf,1023,0,(struct sockaddr*)&other1,&len);
        printf("B ,cLient give me:%s\n",buf);
        in_port_t temport1=ntohs(other1.sin_port);
        memset(port,0,sizeof(port));
        sprintf(port,"%u",temport1);


        printf("B,port=%s\n",port);
        //printf("hhhhhh\n");
        sendto(fd1,buf,strlen(buf),0,(struct sockaddr*)&other,sizeof(struct sockaddr_in));
        sendto(fd1,"OKOKOK",6,0,(struct sockaddr*)&other1,sizeof(struct sockaddr_in));

       
        return 0;

}
                 
