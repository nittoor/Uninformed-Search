#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <sstream>
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "UniformCostSearch.h"

const string BFS_RESULT_FILE= "breadth-first.result.txt";
const string DFS_RESULT_FILE= "depth-first.result.txt";
const string UCS_RESULT_FILE= "uniform-cost.result.txt";

using namespace std;

bool loadAdjMatrixFromFile(ifstream &,vector<vertex>& nameString,vector<vector<int> > & matrix);
bool is_number(const std::string& s);

int main(int argc, char* argv[])
{
	if (argc!=2)
	{
		cerr<<"Usage ExecutableName <filename>"<<endl;
		exit(1);
	}

	const string inputFileName=argv[1];
	ifstream inputFile(inputFileName.c_str());
	
	if (!inputFile)
	{
		cerr << "Uh oh, " << inputFileName << " could not be opened for reading!" << endl;
        exit(1);
	}
	 
	vector<vector<int> > adjMatrix;
	vector<vertex> nameVector;

	if(!loadAdjMatrixFromFile(inputFile,nameVector,adjMatrix))
	{
		cerr << "Uh oh, failed in loadAdjMatrixFromFile" << endl;
		exit(1);
	}

	

	string asdf;
	
	cout << "\n=========================================================================================\n";
	DepthFirstSearch depthFirstObject(nameVector.size(),nameVector,DFS_RESULT_FILE);
	depthFirstObject.fillAdjMatrix(adjMatrix);
	depthFirstObject.returnSolution("Alice","Noah",asdf);
	cout<<asdf;
	//test code
	cout << "\n=========================================================================================\n";
	cout << "\n=========================================================================================\n";
	//bfs
	asdf.clear();
	BreadthFirstSearch breadthFirstObject(nameVector.size(),nameVector,BFS_RESULT_FILE);
	breadthFirstObject.fillAdjMatrix(adjMatrix);
	breadthFirstObject.returnSolution("Alice","Noah",asdf);
	cout<<asdf;
	//BFS
	asdf.clear();
	cout << "\n=========================================================================================\n";
	cout << "\n=========================================================================================\n";
	
	//ucs
	UniformCostSearch UniformSearchObject(nameVector.size(),nameVector,UCS_RESULT_FILE);
	UniformSearchObject.fillAdjMatrix(adjMatrix);
	UniformSearchObject.returnSolution("Alice","Noah",asdf);
	cout<<asdf;
	//ucs
	
	cout << "\n=========================================================================================\n";
	
	cout<<"Hit any key to exit!!"<<endl;
	getchar();
}

bool loadAdjMatrixFromFile(ifstream & inputFile,vector<vertex>& nameString,vector<vector<int> >  & matrix)
{
	bool flagForEndOfNames=false;
	while (inputFile)
	{
		string line;
		getline(inputFile,line);
		if (!is_number(line))
		{
			if (flagForEndOfNames)
				break;
			vertex tempVertexObject(line);
			nameString.push_back(tempVertexObject);
		}
		else
		{
			flagForEndOfNames=true;
			vector<int> tempVector;
			int n;
			stringstream tempLine(line);
			while (1)
			{
				tempLine>>n;
				if (!tempLine)
					break;
				tempVector.push_back(n);
			}
			matrix.push_back(tempVector);
		}
	}

	cout<<endl;

	return true;
}

bool is_number(const std::string& s)
{
	return isdigit(*(s.begin()));
}
