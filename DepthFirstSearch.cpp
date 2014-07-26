#include "DepthFirstSearch.h"

DepthFirstSearch::DepthFirstSearch(int x,const vector<vertex>& nameArray,const string & outFile):UninformedSearchSolution(x,nameArray,outFile),numberOfVertices(x)
{
}

int DepthFirstSearch::returnSolution(const string & start, const string & end, string & sol)
{
	int startIndex=AdjacencyMatrix.getNameIndex(start);
	int endIndex=AdjacencyMatrix.getNameIndex(end);
	
	if (DFS(startIndex,endIndex))
	{
		cout<<"DFS solution found!\n";
		printSolution(endIndex,sol);
		sol.erase(sol.end()-1);
	}

	ofstream dfsOutputFile(outputFileName.c_str(),ios::out);
	if (!dfsOutputFile)
	{
		cerr << "Uh oh, " << outputFileName << " could not be opened for writing!" << endl;
		exit(1);
	}
	
	dfsOutputFile<<sol;
	dfsOutputFile.close();

	return 1;
	
}


int DepthFirstSearch::DFS(const int start, const int end)
{
	if (start==end)
	{
		return 1;
	}
	AdjacencyMatrix.getVertex(start).color=GREY;
	//int nextAdj=AdjacencyMatrix.getAdj(start);
	vector<int> nextAdjVec=AdjacencyMatrix.getSortedAdjVertices(start);
	for(int i =0;i<nextAdjVec.size();i++ )
	{
		if (AdjacencyMatrix.getVertex(nextAdjVec[i]).color==WHITE)
		{
			AdjacencyMatrix.getVertex(nextAdjVec[i]).parent=start;
			AdjacencyMatrix.getVertex(nextAdjVec[i]).depth=AdjacencyMatrix.getVertex(start).depth+1;
			if (DFS(nextAdjVec[i],end))
			{
				return 1;
			}
		}
	}
	/*
	for(;nextAdj <numberOfVertices; )
	{
		if (AdjacencyMatrix.getVertex(nextAdj).color==WHITE)
		{
			AdjacencyMatrix.getVertex(nextAdj).parent=start;
			AdjacencyMatrix.getVertex(nextAdj).depth=AdjacencyMatrix.getVertex(start).depth+1;
			if (DFS(nextAdj,end))
			{
				return 1;
			}
		}
		nextAdj=AdjacencyMatrix.getAdj(start);
	}
	*/
	AdjacencyMatrix.getVertex(start).color=BLACK;
	return 0;
}

DepthFirstSearch::~DepthFirstSearch()
{
}
