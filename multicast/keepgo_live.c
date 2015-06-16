#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdlib.h>
#include <arpa/inet.h>

/**
 *filename:simple_udpclient.c
 *purpose:基本编程，演示UDP编程的客户端编程步骤
 */

#define IP "10.5.5.9"

int main(int argc, char *argv[])
{
  struct sockaddr_in servaddr;
  int sockfd;
  int addr_len;
  int len;
  char buff[128];

  /*创建socket，关键在于在SOCK_DGRAM*/
  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
    perror("socket");
    exit(errno);
  }else
    printf("created socket.\n\r");

  /*设置对方的地址和端口信息*/
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(8554);
  servaddr.sin_addr.s_addr = inet_addr(IP);
  }
  /*发送UDP消息*/
  addr_len = sizeof(servaddr);
  strcpy(buff, "_GPHD_:0:0:2:0.000000");
  while(true){
	  len = sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr*)&servaddr, addr_len);
	  if(len < 0){
	    printf ("\n\rsend error.\n\r");
	    return 3;
	  }
  }
  printf ("send success.\n");
  return 0;
}

