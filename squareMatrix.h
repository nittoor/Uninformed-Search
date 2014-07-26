#include <vector>

#include <string>

using namespace std;

template <typename T>
class squareMatrix
{
public:
	squareMatrix(int x){
		square.resize(x);
		for (int i=0;i<x;i++)
		{
			square[i].resize(x);
		}
	}

	T & operator () (const int u,const int v)
	{
		return square[u][v];
	}

	const T & operator () (int u,int v) const
	{
		return square[u][v];
	}

	vector<T> & operator () (int u)
	{
		return square[u];
	}

	~squareMatrix()
	{
		for (int i=0;i<square.size();i++)
			square[i].clear();
	}
private:
	vector<vector<T> > square;
	squareMatrix();
};
