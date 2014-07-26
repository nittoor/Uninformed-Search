#include "AdjMatrix.h"

AdjMatrix::AdjMatrix(int x,const vector<vertex>& nameArray):AdjMatrixHolder(x)
{
	NameIndex=nameArray;
	prevIndex.resize(x,-1);
}

vector<int> AdjMatrix::getAdjVertices(const int x)
{
	vector<int> temp = AdjMatrixHolder(x);
	vector <int> result;
	for (int it=0;it<temp.size();it++)
	{
		if (temp[it]!=0)
		{
			result.push_back(it);
		}
			
	}

	return result ;

}

vector<int> AdjMatrix::getSortedAdjVertices(const int x)
{
	vector<int> temp = getAdjVertices(x);
	vector <int> result;
	int rt,it;
	for (it=0;it<temp.size();it++)
	{
		for (rt=0;rt<result.size() && NameIndex[result[rt]].name<NameIndex[temp[it]].name ;rt++)
		{
		}
		result.insert(result.begin()+rt,temp[it]);
	}

	return result ;

}

int AdjMatrix::getAdj(const int x)
{
	int & start = prevIndex[x];
	if ( start==-1 || start<prevIndex.size())
	{
		while( start==-1 || start<prevIndex.size()){
		if (AdjMatrixHolder(x,++start))
		{
			break;
		}
		}
		return start;
	}
	else 
		return -1;
}

bool AdjMatrix::fillAdjMatrixRow( const vector<int> & inputRow ,const int rowId)
{
	AdjMatrixHolder(rowId).insert(AdjMatrixHolder(rowId).begin(),inputRow.begin(),inputRow.end());
	return true;
}

int AdjMatrix::getCost(int u, int v)
{
	return AdjMatrixHolder(u,v);
}

int AdjMatrix::getNameIndex(const string name)
{
	for (int i =0; i< NameIndex.size();i++)
	{
		if (NameIndex[i].name==name)
		{
			return i;
		}
	}
	return -1;
}

vertex & AdjMatrix::getVertex(const int u)
{
	return NameIndex[u];
}

void AdjMatrix::printAdjMatrix()
{
	std::cout<< "\t";
	int i;
	for (i=0;i<NameIndex.size();i++)
	{
		cout<<NameIndex[i].name<<"\t";
	}
	cout << endl<<"\t";
	for (i=0;i<NameIndex.size();i++)
	{
		cout<<i<<"\t";
	}
	cout<<endl<<endl<<endl;

	for (i=0;i<NameIndex.size();i++)
	{
		cout <<i<<"\t";
		for (int j=0;j<NameIndex.size();j++)
		{
			cout<<AdjMatrixHolder(i,j)<<"\t";
		}
		cout<<endl;
	}
}

AdjMatrix::~AdjMatrix(){
} 
