#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int main()
{
	int n,start,finish,source,i,x,j;
	cin>>n;

	vector<vector<int>> v(n+1);
	vector<bool> vbool(n+1,false);

	cin>>x;
	for(i=1;i<=x;i++)
	{
		cin>>start>>finish;
		v[start].push_back(finish);
        v[finish].push_back(start);
	}

	/*for(i=1;i<=n;i++)
    {
        for(j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }*/

	cin>>source;

	//bfs;
	//cout<<endl;
	queue<int> q;

	q.push(source);
	vbool[source] = true;

	while(q.empty()==0)
	{
		for(i=0;i<v[q.front()].size();i++)
		{
			if(vbool[v[q.front()][i]]==false)
			{
					q.push(v[q.front()][i]);
					vbool[v[q.front()][i]] = true;
			}
		}
		cout<<q.front()<<" ";
		q.pop();
	}

	cout<<endl;

	//dfs
    vector<bool> vbool2(n+1,false);

	stack<int> s;
	s.push(source);
	vbool2[source]  = true;
	int tempo;
	while(s.empty() == 0)
    {
        cout<<s.top()<<" ";
        tempo = s.top();
        s.pop();
        for(i=0;i<v[tempo].size();i++)
        {
            if(vbool2[v[tempo][i]] == false)
            {
                s.push(v[tempo][i]);
                vbool2[v[tempo][i]] = true;
            }
        }
    }
return 0;
}
