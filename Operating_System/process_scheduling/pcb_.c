#include<stdio.h>
#include<stdlib.h>
struct pcb
{
    char * name;//进程名
    int pri;//进程优先数
    // int round ;//进程轮转时间片
    int cputime;//进程占用的CPU时间
    int needtime;//进程到完成还要的时间
    char state;//进程状态ready:w,run:r,finish:f
    struct pcb* next;//链指针
}* a,*head=NULL;//head 表示就绪队列的首指针

void sort(){
    if(head==NULL||(a->pri)>(head->pri)){
        a->next=head;
        head=a;
    }else{
        struct pcb* first;
        struct pcb* second;
        first=head;
        second=head->next;
        int fg=0;
        while(second!=NULL){
            if((a->pri)>(second->pri)){
                first->next=a;
                a->next=second;
                fg=1;
                break;
            }else{
                first=second;
                second=second->next;
            }
        }
        if(fg==0)//表示上述循环没有插进去
            first->next=a;
    }
}
/*
1） 系统初始化时给每一个进程赋一个NEEDTIME和初始PRI。并按优先数入队。
2） 系统每次选定一个优先级最高的进程投入运行，进程每执行一次，并将它的进程占用的CPU时间加10，进程到完成还要的CPU时间减10。
3） 每当一个进程运行一个时间片后,系统根据它的CPUTIME来判断它是否已经结束,若CPUTIME>0,那么将它重新排入就绪队列。
4） 如果系统中尚有进程没有运行完毕,那么转入2）。
*/
void init(){
    printf("请输入进程数\n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("请输入进程名");
        a=(struct pcb*)malloc(sizeof(struct pcb));
        scanf("%s",a->name);
        printf("请输入进程优先数");
        scanf("%d",&a->pri);
        printf("请输入进程运行所需时间");
        int needtime;
        scanf("%d",&a->needtime);
        a->cputime=0;
        a->next=NULL;
        a->state='w';
        sort();
    }
}
int getreadynum(){
    int res=0;
    struct pcb *temp=head;
    while(temp!=NULL){
        res++;
        temp=temp->next;
    }
    return res;
}
void destroy(){
    printf("\n *process [%s] finished*\n",a->name);
    free(a);
}
void run(){
    printf("正在运行%s\n",a->name);
    if(a->needtime>10){
        a->cputime+=10;
        a->needtime-=10;
        a->pri-=1;
        sort();
    }
    else {
        destroy();
    }
}
void show(struct pcb* p){
    printf("\n name \t state \t pri \t needtime \t cputime \n");
    printf("|%s\t",p->name);
    printf("|%c\t",p->state);
    printf("|%d\t",p->pri);
    printf("|%d\t",p->needtime);
    printf("\t|%d\t",p->cputime);
    printf("\n");
}
void showfuck(){
    struct pcb* p;
    p=head->next;
    printf("*the running process is:%s*\n",a->name);
    show(a);
    printf("**the wait queue:**\n");
    while(p!=NULL){
        show(p);
        p=p->next;
    }
}

int main(){
    //a指向正在运行的进程
    //head指向就绪队列的头

    int len;
    char ch;
    init();
    len=getreadynum();
    while(head!=NULL){
        a = head;
        head = a->next;
        a->next = NULL;
        a->state = 'R';
        showfuck();
        run();
        system("pause");
    }
    printf("\n\n*进程已经完成*\n");

}
