objects = ALGraph.o Operation.o Assist.o

ALGraph : $(objects)
ifeq ($(shell uname), MINGW32_NT-6.2)
	gcc -o ALGraph.exe $(objects);
else
	gcc -o ALGraph.out $(objects);
endif

ALGraph.o : ALGraph.c BaseData.h
	gcc -c ALGraph.c
Operation.o : Operation.c BaseData.h
	gcc -c Operation.c
Assist.o : Assist.c Assist.h
	gcc -c Assist.c
	
clean :
ifeq ($(shell uname), MINGW32_NT-6.2)
	-rm ALGraph.exe $(objects)
else
	-rm ALGraph.out $(objects)
endif