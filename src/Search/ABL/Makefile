objects = ABL.o Operation.o

ABL: $(objects)
ifeq ($(shell uname), MINGW32_NT-6.2)
	gcc -o ABL.exe $(objects)
else
	gcc -o ABL.out $(objects)
endif
ABL.o : ABL.c BaseData.h
	gcc -c ABL.c
Operation.o : Operation.c BaseData.h
	gcc -c Operation.c
rm : 
	rm ABL.exe $(objects);