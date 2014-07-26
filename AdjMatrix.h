#include <iostream>
#include <vector>
#include <string>
#include "squareMatrix.h"

using namespace std;

enum colorCode{
	WHITE,
	GREY,
	BLACK
};

struct vertex{
	vertex(string naa=NULL,int paa =-1,colorCode col = WHITE, int dep=-1):parent(paa),color(col),depth(dep),name(naa)
	{}
	int parent;
	colorCode color;
	int depth;
	string name;
};


class AdjMatrix {
public:
	AdjMatrix(int x,const vector<vertex>& nameArray);
	int getAdj(const int x);
	int getNameIndex(const string name);
	bool fillAdjMatrixRow(const vector<int> & inputRow , int rowId);
	int getCost(int u, int v);
	vertex & getVertex(int u);
	vector<int> getAdjVertices(const int x);
	vector<int> getSortedAdjVertices(const int x);
	void printAdjMatrix();
	~AdjMatrix(); 
private:
	AdjMatrix();
	squareMatrix<int> AdjMatrixHolder;
	vector<vertex> NameIndex;
	vector<int> prevIndex;
};
