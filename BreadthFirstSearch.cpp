#include "BreadthFirstSearch.h"

BreadthFirstSearch::BreadthFirstSearch(int x,const vector<vertex>& nameArray,const string & outFile):UninformedSearchSolution(x,nameArray,outFile),numberOfVertices(x)
{
}

BreadthFirstSearch::~BreadthFirstSearch()
{
}


int BreadthFirstSearch::returnSolution(const string & start, const string & end,  string & sol)
{
	int startIndex=AdjacencyMatrix.getNameIndex(start);
	int endIndex=AdjacencyMatrix.getNameIndex(end);
	queue.push(startIndex);
	AdjacencyMatrix.getVertex(startIndex).color=GREY;
	if(BFS(endIndex))
	{
		cout<<"BFS solution found\n";
		printSolution(endIndex,sol);
		sol.erase(sol.end()-1);
	}

	ofstream bfsOutputFile(outputFileName.c_str(),ios::out);
	if (!bfsOutputFile)
	{
		cerr << "Uh oh, " << outputFileName << " could not be opened for writing!" << endl;
		exit(1);
	}
	
	bfsOutputFile<<sol;
	bfsOutputFile.close();


	return 1;
}

int BreadthFirstSearch::BFS(const int & end)
{
	while(queue.size())
	{
		int currentNode=queue.front();
		queue.pop();
		if(end==currentNode)
		{
			return 1;
		}
		vector<int> AdjVertexIndex=AdjacencyMatrix.getAdjVertices(currentNode);
		/*
		cout << "Adjacent vertices to node "<< currentNode<< "=";
		for (int i=0;i<AdjVertexIndex.size();i++)
		{
			cout <<AdjVertexIndex[i];
		}
		cout<<endl;
		*/
		AdjVertexIndex=AdjacencyMatrix.getSortedAdjVertices(currentNode);

		/*
		cout << "Rearranged Adjacent vertices to node "<< currentNode<< "=";
		
		for (int i=0;i<AdjVertexIndex.size();i++)
		{
			cout <<AdjVertexIndex[i];
		}
		cout<<endl;
		*/
		for (int i=0;i<AdjVertexIndex.size();i++)
		{
			if (AdjacencyMatrix.getVertex(AdjVertexIndex[i]).color==WHITE)
			{
				AdjacencyMatrix.getVertex(AdjVertexIndex[i]).parent=currentNode;
				AdjacencyMatrix.getVertex(AdjVertexIndex[i]).color=GREY;
				AdjacencyMatrix.getVertex(AdjVertexIndex[i]).depth=AdjacencyMatrix.getVertex(currentNode).depth+1;
				queue.push(AdjVertexIndex[i]);
			}
		}

		AdjacencyMatrix.getVertex(currentNode).color=BLACK;

	}
	return 0;
}
