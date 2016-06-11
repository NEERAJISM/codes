#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,src,b[100],i,j,v[100][100];
	queue<int> q;
	stack<int> s;
	cout<<"enter the no. of nodes : ";
	cin>>n;

	for(i=1;i<=n;i++)
	{
		cout<<"enter the no. of vertices connected to "<<i<<"th node : ";
		cin>>v[i][0];

		for (j=1 ; j<=v[i][0] ; j++)
		{
		    //cout<<"***/*";
			cin>>v[i][j];
		}
		b[i] =0;
	}

	cout<<"enter the source vertex : ";
	cin>>src;

	cout<<"the breadth first search is : ";
	q.push(src);
	b[src] =1;

	while(q.empty()!=1)
	{
		for(i=1 ; i<=v[q.front()][0] ; i++)
		{
			if(b[v[q.front()][i]] != 1)
			{
				q.push(v[q.front()][i]);
				b[v[q.front()][i]] =1;
			}
		}
		cout<<q.front()<<" ";
		q.pop();
	}

	cout<<endl<<"the depth first search is : ";
	s.push(src);
	b[src] = 0;

	while(s.empty()!=1)
	{
		int temp = s.top();
		cout<<s.top()<<" ";
		s.pop();

		for(i=1 ; i<=v[temp][0] ; i++)
		{
			if(b[v[temp][i]] != 0)
			{
				s.push(v[temp][i]);
				b[v[temp][i]] = 0;
			}
		}
	}
return 0;
}
