#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct pcb{
    char name[10];
    int round;
    int cputime;
    int needtime;
    char state;//o:ready ,r:run ,f:finish
    struct pcb* next;//链指针
}*ready=NULL,*temp;//ready 是就绪队列的首指针,temp 是临时指针
typedef struct pcb PCB;
int count=0;//全局变量,表明当前队列内的pcb块数
/*
1） 系统初始化时给每一个进程赋以一个needtime，
并将所有进程按进入的次序排成一个队列。
2） 取队头进程,并投入运行。
3） 采用相对固定时间片（round），进程每执行一次，
进程占用的CPU时间加ROUND，进程到完成还要的CPU时间减round。
并排到就绪队列的尾部。
4） 如果当前进程的needtime>0,那么将它排到队尾。
5） 如果尚有进程在队列中,那么转入2）。
*/

void init(){
    printf("\n请输入运行的进程数");
    int n;
    scanf("%d",&n);
    count=n;
    for(int i=0;i<n;i++){
        temp=(PCB*)malloc(sizeof(PCB));
        printf("\n请输入进程名:");
        scanf("%s",temp->name);
        printf("\n请输入运行时间片:");
        scanf("%d",&(temp->round));
        printf("\n请输入进程需要的运行时间:");
        scanf("%d",&temp->needtime);
        temp->cputime=0;
        temp->state='o';
        temp->next=NULL;
        //创建进程完毕后,将temp进程移至队尾
        if(ready!=NULL){
            PCB* a=ready;
            while(a->next!=NULL)
                a=a->next;
            a->next=temp;
        }else {
            ready=temp;
        }
    }
}

void out(){
    //
    printf("进程%s运行完毕,运行时间:%d\n",temp->name,temp->cputime);
    free((void* )temp);
    temp=ready;
    if(count>1)
    ready=ready->next;
    count--;
}

void sort(){
    //在这里temp指向的是队首正在运行的PCB
    PCB * a=temp;
    if(count==1)return ;
    int fuck=count;
    while(fuck--!=1){
        a=temp->next;
    }
    ready=temp->next;
    temp->next=NULL;
    //此时a指向队尾元素
    a->next=temp;

    temp=ready;
    ready=ready->next;
}

void run(){
    //此时临时指针temp指向待运行的pcb
    if(temp->needtime<=temp->round){
        //说明已经运行完毕
        (temp->cputime)+=(temp->round);
        out();//执行收尸的代码
    }
    else{
        (temp->cputime)+=(temp->round);
        (temp->needtime)-=(temp->round);
        (temp->state)='o';//进入就绪队列
        sort();//执行将temp所指的pcb移入队尾
    }
    
}
int main(){
    init();//初始化
    //初始化后,ready 指向队首,temp指向最后插入的元素
    temp=ready;
    ready=ready->next;
    while(count>0){
        temp->state='r';
        run();
        //system("pause");
    }
}