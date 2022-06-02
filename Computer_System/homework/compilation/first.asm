pushl %ebp ; 

movl %esp, %ebp

pushl %ebx ;将ebx中的内容压入栈,ebx中存着程序运行的下一位置

movl 8(%ebp), %ecx ;将函数第一个参数传入ecx 即x 

movl 12(%ebp), %edx ;将函数第二个参数传入edx 即y

movl 12(%ebp), %eax ;将函数第二个参数传入eax 即y

addl %eax, %eax ;eax加上eax

addl 8(%ebp), %eax ;将x加上eax 即x+2*y

sall $4, %ecx ;x*16

leal (%ecx,%edx), %edx ;x*16+y

movl %eax, array1(,%edx,4) ;x*64+4*y+array1 寻址并将x+2*y 传入:由此推出 J=16

movl 12(%ebp), %edx ;y传入edx

movl 8(%ebp), %ebx ;x传入ebx

movl 8(%ebp), %eax ;x传入eax

imull 8(%ebp), %eax ;x*x传入eax

movl 12(%ebp), %ecx ;y传入ecx

subl%eax, %ecx ;y-x*x 传入ecx
 
movl %edx, %eax ;y传入eax

sall$3, %eax ;y*8->eax

addl%edx, %eax;y*8+y->eax

sall$2, %eax;9*y*4->eax

addl%edx, %eax;36*y+y->eax

addl%ebx, %eax;37*y+x->ebx

movl%ecx, array2(,%eax,4);y-x*x->array2[4*37*y+4*x]可推出:H=37

popl%ebx

popl%ebp ;返回

ret