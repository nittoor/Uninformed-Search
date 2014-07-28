OBJS = AdjMatrix.o UninformedSearchSolution.o BreadthFirstSearch.o DepthFirstSearch.o UniformCostSearch.o Source.cpp
CC = g++
DEBUG = -g
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

assign1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) squareMatrix.h -o program
	
Source.o : BreadthFirstSearch.h DepthFirstSearch.h DepthFirstSearchWithArray.h UninformedSearchSolution.h UniformCostSearch.h
	$(CC) $(CFLAGS) Source.cpp

BreadthFirstSearch.o : BreadthFirstSearch.h BreadthFirstSearch.cpp AdjMatrix.h UninformedSearchSolution.h squareMatrix.h
	$(CC) $(CFLAGS) BreadthFirstSearch.cpp

DepthFirstSearch.o : DepthFirstSearch.h DepthFirstSearch.cpp AdjMatrix.h UninformedSearchSolution.h squareMatrix.h
	$(CC) $(CFLAGS) DepthFirstSearch.cpp
    
UniformCostSearch.o : UniformCostSearch.h UniformCostSearch.cpp AdjMatrix.h UninformedSearchSolution.h squareMatrix.h
	$(CC) $(CFLAGS) UniformCostSearch.cpp

UninformedSearchSolution.o : UninformedSearchSolution.h UninformedSearchSolution.cpp AdjMatrix.h 
	$(CC) $(CFLAGS) UninformedSearchSolution.cpp

AdjMatrix.o : AdjMatrix.h AdjMatrix.cpp squareMatrix.h
	$(CC) $(CFLAGS) AdjMatrix.cpp
    
squareMatrix.o : squareMatrix.h
	$(CC) $(CFLAGS) squareMatrix.h

clean:
	\rm *.o program
