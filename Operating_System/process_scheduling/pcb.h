#define NULL 0
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
