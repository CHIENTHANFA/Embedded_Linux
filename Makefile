var = "1"
var2 := $(var)
var3 = $(var)
var4 ?= $(var)
var = "2"
test: 
	@echo $(var2)
	@echo $(var3)
	@echo $(var4)
rule3: main.c 
	@echo $@
	@echo $^
	@echo $<
hello: 
	gcc main.c -o hello

stage1:
	gcc -E hello.c -o hello.i

stage2:
	gcc -S hello.i -o hello.S

stage3:
	gcc -c hello.S -o hello.o

stage4:
	gcc -o hello hello.o

all:
	gcc -o hello hello.c

clean:
	rm -rf hello hello.i hello.S hello.o
	rm -rf *.o
create_obj:
	gcc -c -o main.o main.c
	gcc -c -o hello_chien.o hello_chien.c
	gcc -c -o hello_linux.o hello_linux.c