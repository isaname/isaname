#高阶的makefile编写
cc = gcc #定义变量
OBJS = main.o func.o #方便重复利用 
main.exe : $(OBJS)  #所有的目标文件与所有的依赖文件
	@$(cc) $(OBJS) -o $@
%.o : %.c
	@$(cc) -c $^ -o $@

.PHONY:
clean:
	@rm -rf $(OBJS)