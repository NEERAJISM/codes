#include <iostream>
#include <climits>
using namespace std;
int traversed[50],key[50][2],path[50],k =0;

int findmin(int n)
{
	int min = INT_MAX, minindex;
	for (int i = 0; i < n; ++i)
	{
		if(key[i][0] < min && traversed[i] == 0)
		{
			min = key[i][0];
			minindex = i;
		}
	}
	return minindex;
}


void prims(int g[][],src,n)
{
	int temp,j1;
	for (int i = 0; i < n; ++i)
		key[i][0] = INT_MAX;

	key[src][0] = 0;
	key[src][1] = -1;

	for (int i = 0; i < n-1; ++i)
	{
		int minpoint = findmin(n);

		traversed[minpoint]  == 1;
		path[k]  = minpoint;
		k++;

		//update

		temp = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			if(g[minpoint][j] < temp && traversed[j] ==0 && key[])	
			{
				temp =g[minpoint][j];
				j1 = j;
			}
		}
		key[minpoint] = temp; 
	}
}

int main()
{
	int n,g[50][50],src;
	cout<<"enter the no. edges in the graph :";
	cin>>n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin>>g[i][j];

	cout<<"enter the source vertex : "
	cin>>src;

	path[k] = src;
	k++;

	prims(g,n,src);

return 0;
}