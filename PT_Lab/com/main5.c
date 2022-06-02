#include <stdio.h>
#include "com.h"
#include "com.c"
 
int main(void)
{
	unsigned char tmp[30] = {0}; //用于存放读取出来的数据的缓冲区
	int rl; //读取数据的长度（单位：字节）
	int i;
    unsigned char tmp2[30]={0};//用来保存前一次读出的数据
	fd = openSerial("/dev/ttyUSB0"); //打开串口，ttyUSB0是串口文件
	
	if(fd < 0)
	{
		printf("open com fail!\n");
		return 0;
	}
	
	EpollInit(fd); //初始化终端事件触发函数epoll,设置要监听的事件及相关参数等
	unsigned char forwrite[20]={0xAA,0x55, 0x02, 0x00, 0x02 ,0x00 ,0x00, 0x09, 0x00, 0x06, 0x00 ,0x04, 0x02 ,0x04};
    
    write(fd,forwrite,14);
    unsigned char pwd[6]={0};
	while(1)
	{
		while(rl!=6){
        	rl=ComRead(pwd,6);
		}
		//打印读到的数据
		printf("read_len = %d\n", rl);
		for(i = 0; i < rl; i++)
			printf(" %02x", pwd[i]);
		printf("\n\n");
        // forwrite[0]=0xAA;
        // forwrite[1]=0x55;
        // for(int i=0;i<4;i++){
        //     forwrite[i+2]=tmp[-4+i];
        // }
        write(fd,pwd,6);
        //bzero(pwd,6);
        //sleep(1);
	}
	
	close(epid);
	close(fd);
	
	return 0;
}
