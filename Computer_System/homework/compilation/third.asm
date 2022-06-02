frac:;伪代码,函数frac的起始地址

pushl %ebp;栈底指针压栈

movl %esp, %ebp;栈底指针指向栈顶指针所在处

subl$24, %esp;栈顶指针向下开辟24字节的空间

cmpl$1, 8(%ebp);将1和传入的参数a进行比较,假设参数为H

jg.L2;如果1<H跳转到.L2

movl 8(%ebp), %eax;H->eax

imull 8(%ebp), %eax;原来存储a的位置变为a*a

jmp.L3;无条件跳转到.L3

.L2:;伪代码

movl 8(%ebp), %eax;第一个参数给eax,H->eax

subl$2, %eax;eax-2->eax(H-2->eax)

movl%eax, (%esp);将eax的内容写入esp指针所指处

call frac;调用frac

addl 8(%ebp), %eax;第一个参数加上eax,H+eax->eax

.L3:;伪代码

leave;返回

ret;返回

sum:;函数首地址

pushl%ebp;栈底指针压栈

movl %esp, %ebp;栈底指针指向栈顶指针所指处

subl$40, %esp;栈顶指针向下开辟40个字节空间

movl 12(%ebp), %eax;第二个参数传入eax

movl 8(%ebp), %edx;第一个参数传入edx

addl %edx, %eax;edx+eax->eax

movl%eax, (%esp);将eax内容写入esp 所指处,

call frac;调用frac

movl %eax, -12(%ebp);将eax内容写入ebp向下12字节空间

movl-12(%ebp), %eax;写回

addl%eax, %eax;eax+eax->eax

addl 12(%ebp), %eax;第二个参数传入eax eax+b->eax

leave;返回

ret;返回

main:;主函数

pushl %ebp;栈底指针压栈

movl %esp, %ebp;栈底指针指向栈顶指针所指处

andl$-16, %esp;栈顶指针与16相与,使地址成为16的倍数

subl$32, %esp;esp 向下开辟32字节空间

movl$10, 20(%esp);10存入esp向上20字节位置,假设该位置为变量I

movl$6, 24(%esp);将6存入esp向上24字节位置,假设该位置为J

movl 20(%esp), %eax;I->eax

movl 24(%esp), %edx;J->edx

subl%eax, %edx;J-I->edx

movl 20(%esp), %eax;I->eax

addl$1, 20(%esp);I+1->I

movl%edx, 4(%esp);J-I->b

movl%eax, (%esp);I+1->a

call sum;调用sum

movl%eax, 28(%esp);eax 写入esp向上28字节内存空间,假设为K

movl$0, %eax;eax置0

leave;返回

ret;返回