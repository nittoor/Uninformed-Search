#ifndef USS
#define USS

#include <iostream>
#include <fstream>
#include "AdjMatrix.h"
#include <string>
#include <functional>


using namespace std;

class UninformedSearchSolution
{
public:
	UninformedSearchSolution(int x,const vector<vertex>& nameArray,const string & outFile);
	~UninformedSearchSolution();
	virtual int returnSolution(const string & start, const string & end,  string & sol)=0;
	void fillAdjMatrix(const vector<vector<int> > &);
	bool printSolution(const int endIndex,string & solution);
	bool rearrangeAdjVectorByName(vector<int> & arrangeByName);
protected:
	 AdjMatrix AdjacencyMatrix;
	string outputFileName;

};

#endif
