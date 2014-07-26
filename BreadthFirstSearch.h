#include <queue>
#include "UninformedSearchSolution.h"

class BreadthFirstSearch:public UninformedSearchSolution
{
public:
	BreadthFirstSearch(int x,const vector<vertex>& nameArray,const string & outFile);
	virtual int returnSolution(const string & start, const string & end,  string & sol);
	int BFS(const int &);
	~BreadthFirstSearch();

private:
	int numberOfVertices;
	queue<int> queue;
	BreadthFirstSearch();

};
