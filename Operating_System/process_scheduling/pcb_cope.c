 
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h> 
 
#define getpch(type) (type*)malloc(sizeof(type)) 
 
 
 
struct pcb   /* 定义进程控制块PCB */ {
	char name[10];//存储进程名
	struct pcb* next;  //指针
	int pri;        //优先级数
	int needtime;       //运行时间
	int cputime;
	char state;       //进程状态
}*ready = NULL, *p;
typedef struct pcb PCB;
 
void sort() /* 建立对进程进行优先级排列函数*/ {
	PCB *first, *second;
	int insert = 0;
	if ((ready == NULL) || ((p->pri) > (ready->pri))) /*优先级最大者,插入队首*/
	{
		p->next = ready;//插入的数据作为链表头结点
		ready = p;//头结点指针指向插入数
	}
 
	else /* 进程比较优先级,插入适当的位置中*/ {
		first = ready;
		second = first->next;
		while (second != NULL)
		{
			if ((p->pri) > (second->pri)) /*若插入进程比当前进程优先数大,*/
			{ /*插入到当前进程前面*/
				p->next = second;
				first->next = p;
				second = NULL;
				insert = 1;
			}
			else /* 插入进程优先数最低,则插入到队尾*/
			{
 
				first = first->next;
				second = second->next;
			}
		}
		if (insert == 0)
			first->next = p;
	}
}
 
void input() /* 建立进程控制块函数*/
{
	int i, num;
	printf("\n 请输入进程数:");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		printf("\n 进程号%d:\n", i + 1);
		p = getpch(PCB);
		printf("\n 输入进程名:");
		scanf("%s", p->name);
		printf("\n 输入进程优先数:");
		scanf("%d", &p->pri);
		printf("\n 输入进程运行时间:");
		scanf("%d", &p->needtime);
		printf("\n");
		p->cputime = 0; p->state = 'w';
		p->next = NULL;
		sort(); //调用sort函数
	}
}
 
int space()
{
 
	int len = 0; PCB* pr = ready;
	while (pr != NULL)
	{
		len++;
		pr = pr->next;
	}
	return(len);
}
 
void disp(PCB * pr) /*建立进程显示函数,用于显示当前进程*/
{
	printf("\n name \t state \t pri \t needtime   cputime \n");
	printf("|%s\t", pr->name);
	printf("|%c\t", pr->state);
	printf("|%d\t", pr->pri);
	printf("|%d\t", pr->needtime);
	printf("|%d\t", pr->cputime);
	printf("\n");
 
}
 
void check() // 建立进程查看函数 
{
	PCB* pr;
	printf("\n **** 当前正在运行的进程是:%s", p->name); //显示当前运行进程
	disp(p);
	pr = ready;
	printf("\n ****当前就绪队列状态为:\n"); //显示就绪队列状态
	while (pr != NULL)
	{
		disp(pr);
		pr = pr->next;
	}
}
 
void destroy() /*建立进程撤消函数(进程运行结束,撤消进程)*/
{
	printf("\n 进程 [%s] 已完成.\n", p->name);
	free(p);
}
 
void running() /* 建立进程就绪函数(进程运行时间到,置就绪状态*/
 
{
	(p->cputime)+=10;
    (p->needtime)-=10;
	if ((p->needtime)<=0)
		destroy(); /* 调用destroy函数*/
	else
	{
		(p->pri)--;
		p->state = 'w';
		sort(); /*调用sort函数*/
	}
}
int main(void) /*主函数*/
{
	while (1)
	{
		int len;//
		char ch;
		input();
		len =space();
		while ((len != 0) && (ready != NULL))
		{
			ch = getchar();
			p = ready;
			ready = p->next;
			p->next = NULL;
			p->state = 'R';
			check();
			running();
			system("pause");
		}
 
		printf("\n\n 进程已经完成.\n");
	}
	system("pause");
	return 0;
}