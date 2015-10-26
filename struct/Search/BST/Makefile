objects = Operation.o BST.o

BST : $(objects)
ifeq ($(shell uname), MINGW32_NT-6.2)
	gcc -o BST.exe $(objects)
else
	gcc -o BST.out $(objects)
endif
	
Operation.o : Operation.c BaseData.h
	gcc -c Operation.c
BST.o : BST.c BaseData.h
	gcc -c BST.c
	
clean : 
	rm $(objects)