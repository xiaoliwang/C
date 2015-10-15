# 设置变量
objects = MGraph.o Operation.o Assist.o
MGraph : $(objects)
ifeq ($(shell uname), MINGW32_NT-6.2)
	gcc -o MGraph.exe $(objects)
else
	gcc -o MGraph.out $(objects)
endif
	
# 推导形式
# 默认会使用g++
# MGraph.o : BaseData.h
MGraph.o : MGraph.c BaseData.h
	gcc -c MGraph.c
Operation.o : Operation.c BaseData.h Assist.h
	gcc -c Operation.c
Assist.o : Assist.c Assist.h
	gcc -c Assist.c

#-表示出错不理会
clean : 
ifeq ($(shell uname), MINGW32_NT-6.2)
	-rm MGraph.exe $(objects)
else
	-rm MGraph.out $(objects)
endif

