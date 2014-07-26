#include "UniformCostSearch.h"

UniformCostSearch::UniformCostSearch(int x,const vector<vertex>& nameArray,const string& outFile):UninformedSearchSolution(x,nameArray,outFile),numberOfVertices(x)
{
}

UniformCostSearch::~UniformCostSearch()
{
}


int UniformCostSearch::returnSolution(const string & start, const string & end,  string & sol)
{
	int startIndex=AdjacencyMatrix.getNameIndex(start);
	int endIndex=AdjacencyMatrix.getNameIndex(end);
	Ucsqueue.push_back(state(startIndex,0));
	AdjacencyMatrix.getVertex(startIndex).color=GREY;
	if(UCS(endIndex))
	{
		cout<<"USC solution found\n";
		printSolution(endIndex,sol);
		sol.erase(sol.end()-1);
	}

	ofstream ucsOutputFile(outputFileName.c_str(),ios::out);
	if (!ucsOutputFile)
	{
		cerr << "Uh oh, " << outputFileName << " could not be opened for writing!" << endl;
		exit(1);
	}
	
	ucsOutputFile<<sol;
	ucsOutputFile.close();

	return 1;
}

int UniformCostSearch::UCS(const int end)
{
	while(Ucsqueue.size())
	{
		state currentNode=Ucsqueue.front();
		Ucsqueue.erase(Ucsqueue.begin());
		if(end==currentNode.node)
		{
			return 1;
		}
		vector<int> AdjVertexIndex=AdjacencyMatrix.getAdjVertices(currentNode.node);
		
		/*
		cout << "Adjacent vertices to node "<< currentNode.node<< "=";
		
		for (int i=0;i<AdjVertexIndex.size();i++)
		{
			cout <<AdjVertexIndex[i];
		}
		cout<<endl;
		*/

		AdjVertexIndex=AdjacencyMatrix.getSortedAdjVertices(currentNode.node);

		/*
		cout << "Rearranged Adjacent vertices to node "<< currentNode.node<< "=";
		
		for (int i=0;i<AdjVertexIndex.size();i++)
		{
			cout <<AdjVertexIndex[i];
		}
		cout<<endl;
		*/

		for (int i=0;i<AdjVertexIndex.size();i++)
		{
			if (AdjacencyMatrix.getVertex(AdjVertexIndex[i]).color!=BLACK)
			{
				AdjacencyMatrix.getVertex(AdjVertexIndex[i]).parent=currentNode.node;
				AdjacencyMatrix.getVertex(AdjVertexIndex[i]).color=GREY;
				AdjacencyMatrix.getVertex(AdjVertexIndex[i]).depth=AdjacencyMatrix.getVertex(currentNode.node).depth+1;
				pushIntoQueue(state(AdjVertexIndex[i],AdjacencyMatrix.getCost(currentNode.node,AdjVertexIndex[i])+currentNode.cost));
			}
		}
		/*
		vector<state>::iterator it;
		for (it=Ucsqueue.begin();it<Ucsqueue.end();it++)
			{
				cout<<it->node<<" "<<it->cost<<endl;
			}

		cout<<"=========================="<<endl;
		*/

		AdjacencyMatrix.getVertex(currentNode.node).color=BLACK;

	}
	return 0;
}

int UniformCostSearch::pushIntoQueue(const state nodeState)
{
	vector<state>::iterator it;
	for (it=Ucsqueue.begin();it<Ucsqueue.end() && it->cost<nodeState.cost;it++)
	{
	}
	Ucsqueue.insert(it,nodeState);
	return 1;

}
