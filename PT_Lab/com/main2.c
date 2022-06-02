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
    sleep(3);
	while(1)
	{
		bzero(tmp,sizeof(tmp)); //把tmp对应的内存块的前sizeof(tmp)个字节置零
		bzero(forwrite,sizeof(forwrite));//用于写的内存块清零
		rl=ComRead(tmp,3);//读取3个字节放到缓存
        sleep(1);
        unsigned int position=tmp[2];
        for(i = 0; i < rl; i++)
			printf(" %02x", tmp[i]);
		printf("\n\n");
        bzero(tmp,sizeof(tmp));//清零tmp
        rl=ComRead(tmp,position);//接着读入密码
        sleep(2);
		//打印读到的数据
		printf("read_len = %d\n", rl);
		tmp[rl] = '\0';
		for(i = 0; i < rl; i++)
			printf(" %02x", tmp[i]);
		printf("\n\n");
        forwrite[0]=0xAA;
        forwrite[1]=0x55;
        for(int i=0;i<4;i++){
            forwrite[i+2]=tmp[position-4+i];
        }
        write(fd,forwrite,6);
        sleep(1);
	}
	
	close(epid);
	close(fd);
	
	return 0;
}