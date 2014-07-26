#include <vector>
#include "UninformedSearchSolution.h"

using namespace std;

struct state
{
	state(int n=0,int c=0):node(n),cost(c)
	{
	}
	int node;
	int cost;
};

class UniformCostSearch:public UninformedSearchSolution
{
public:
	UniformCostSearch(int x,const vector<vertex>& nameArray,const string & outFile);
	virtual int returnSolution(const string & start, const string & end,  string & sol);
	int UCS(const int );
	~UniformCostSearch();

private:
	UniformCostSearch();
	int pushIntoQueue(const state nodeState);
	int numberOfVertices;
	vector<state> Ucsqueue;

};