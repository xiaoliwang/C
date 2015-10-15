# 设置变量
objects = MGraph.o Operation.o
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
Operation.o : Operation.c BaseData.h
	gcc -c Operation.c

#-表示出错不理会
clean : 
	-rm MGraph.exe *.o

