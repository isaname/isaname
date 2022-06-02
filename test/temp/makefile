obj=main.o factorial.o
main.exe:factorial.o main.o
	gcc factorial.o main.o -o main.exe
factorial.o:factorial.c
	gcc -c factorial.c -o factorial.o
main.o:main.c
	gcc -c main.c -o main.o
.PHONY:
clean:
	rm -rf $(obj)