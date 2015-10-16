objects = Topo.o Operation.o
Topo : $(objects)
	gcc -o Topo.exe $(objects)
Topo.o : Topo.c BaseData.h
	gcc -c Topo.c
Operation.o : Operation.c BaseData.h
	gcc -c Operation.c
clean :
	rm Topo.exe $(objects);