#include "UninformedSearchSolution.h"

class DepthFirstSearch:public UninformedSearchSolution
{
public:
	DepthFirstSearch(int x,const vector<vertex>& nameArray,const string & outFile);
	virtual int returnSolution(const string & start, const string & end,  string & sol);
	int DFS(const int ,const int);
	~DepthFirstSearch();

private:
	DepthFirstSearch();
	int numberOfVertices;

};