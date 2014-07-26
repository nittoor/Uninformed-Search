#include "UninformedSearchSolution.h"
#include <algorithm>

UninformedSearchSolution::UninformedSearchSolution(int x,const vector<vertex>& nameArray,const string & outFile):AdjacencyMatrix(x,nameArray)
{
	outputFileName=outFile;
}

UninformedSearchSolution::~UninformedSearchSolution()
{
}

void UninformedSearchSolution::fillAdjMatrix(const vector<vector<int> > & matrix)
{
	for (int i=0; i <matrix.size();i++)
	{
		AdjacencyMatrix.fillAdjMatrixRow(matrix[i],i);
	}
	//AdjacencyMatrix.printAdjMatrix();
}

bool UninformedSearchSolution::printSolution(const int endIndex,string & solution)
{
	if (endIndex==-1)
	{
		return true;
	}
	else 
	{
		printSolution(AdjacencyMatrix.getVertex(endIndex).parent,solution);
		//cout << AdjacencyMatrix.getVertex(endIndex).name << "-";
		solution+=(AdjacencyMatrix.getVertex(endIndex).name + "-");
	}
	return true;
}

bool UninformedSearchSolution::rearrangeAdjVectorByName(vector<int> & arrangeByName)
{
	sort(arrangeByName.begin(),arrangeByName.end());
}

