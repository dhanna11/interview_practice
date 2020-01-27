CFLAGS +=  -g
objects = Stack.o UBA.o SetOfStacks.o solution.o
solution: $(objects)

Stack.o: Stack.h
UBA.o: UBA.h
SetOfStacks.o: SetOfStacks.h

default: solution

clean:
	-rm solution $(objects)
