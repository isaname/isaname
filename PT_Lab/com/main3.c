#include <stdio.h>
#include "com.h"
#include "com.c"
 
int main(void)
{
	unsigned char tmp[15] = {0}; //用于存放读取出来的数据的缓冲区
	int rl; //读取数据的长度（单位：字节）
	int i, n = 0;
	unsigned char wr[14] = {0XAA, 0X55, 0X02, 0X00, 0X02, 0X00, 0X00, 0X09, 0X00, 0X06, 0X00, 0X04, 0X02, 0X04};
	unsigned char passwd[6] = {0XAA, 0X55};
	unsigned char s[100] = {0};
	int j;
 
	fd = openSerial("/dev/ttyUSB0"); //打开串口，ttyUSB0是串口文件
	
	if(fd < 0)
	{
		printf("open com fail!\n");
		return 0;
	}
	
	EpollInit(fd); //初始化终端事件触发函数epoll,设置要监听的事件及相关参数等
	write(fd, wr, sizeof(wr));
	
	while(1)
	{
		bzero(tmp,sizeof(tmp)); //把tmp对应的内存块的前sizeof(tmp)个字节置零
		
		rl = ComRead(tmp,15);//读取13个字节放到缓存
         
		//打印读到的数据
		/*printf("read_len = %d\n", rl);
		tmp[rl] = '\0';
		for(i = 0; i < rl; i++)
			printf(" %02x", tmp[i]);
		printf("\n\n");*/
		
		s[n++] = tmp[0];
		if (tmp[0] == 0xaa && n > 0x20) {
			for (j = 0; j < 4; j++) {
				passwd[5 - j] = s[n - j - 2]; 
			}
			write(fd, passwd, sizeof(passwd));
			n = 0;
			for (j = 0; j < 6; j++)
				printf("%2x ", passwd[j]);
			printf("\n");
		}

		
	}
	
	close(epid);
	close(fd);
	
	return 0;
}
