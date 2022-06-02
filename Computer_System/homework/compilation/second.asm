aprod:;一个标志

pushl %ebp;压栈

movl %esp, %ebp ;使栈顶指针和栈底指针指向同一地方

subl$32, %esp ;栈顶指针向下移动32,开辟栈帧

movl$1, -20(%ebp);栈底指针向下的第20个字节存储1

movl$0, -4(%ebp);栈底指针向下4个字节存储0

jmp.L2;无条件跳转到 .L2

.L3:;一个伪指令,表示一个位置

movl-4(%ebp), %eax;将ebp向下4个字节的内存赋给eax,就假设为H

sall$2, %eax;H*4->eax

addl8(%ebp), %eax;a+H->eax

movl(%eax), %eax;a[H]->eax

movl%eax, -8(%ebp);ebp所指内存向下8个字节的位置开始存下eax 

movl-4(%ebp), %eax;H->eax

addl$1, %eax;1+H->eax

sall$2, %eax;4(H+1)->eax

addl 8(%ebp), %eax;a+4(H+1)->eax

movl(%eax), %eax;a[H+1]->eax

movl%eax, -12(%ebp);ebp所指内存向下12个字节的位置开始存下eax 

movl-4(%ebp), %eax;H->eax

addl$2, %eax;H+2->eax

sall$2, %eax;(H+2)*4->eax

addl 8(%ebp), %eax;a+8+4*H->eax

movl(%eax), %eax;a[H+2]->eax

movl%eax, -16(%ebp);ebp所指内存向下16个字节的位置存下eax 

movl -20(%ebp), %eax;J->eax

imull-8(%ebp), %eax;J*a[H+0]->eax

imull-12(%ebp), %eax;J*a[1+H]->eax

imull-16(%ebp), %eax;J*a[2+H]->eax

movl%eax, -20(%ebp);ebp所指内存向下20个字节的位置存下eax

addl$3, -4(%ebp);ebp所指内存向下4个字节的位置存下3+0 

.L2:;伪代码

movl 12(%ebp), %eax;n->eax

subl$2, %eax;n-2->eax

cmpl-4(%ebp), %eax;比较ebp下四内存和eax(n-2)

jg.L3;如果大于跳转到.l3?

jmp.L4;无条件跳转到.L4

.L5:;伪代码

movl-4(%ebp), %eax;假设ebp 向下四个内存存储H ,H->eax

sall$2, %eax;H*4->eax

addl 8(%ebp), %eax;a+4*H->eax

movl(%eax), %eax;a[H]->eax

movl-20(%ebp), %edx;假设ebp向下20个内存存储J,J->edx

imull%edx, %eax;J*a[H]->eax

movl%eax, -20(%ebp);J*a[H]写回 J所在位置

addl$1, -4(%ebp);H=H+1

.L4:

movl-4(%ebp), %eax;H->eax

cmpl 12(%ebp), %eax;比较n和eax(H)

jl.L5;如果 小于则跳转到.L5

movl-20(%ebp), %eax;J->eax

leave;返回

ret;返回