 #include <bits/stdc++.h>
using namespace std;
int a[10000][10000];
int dfs(int src , int n,int r[])
{
	int ct = 0,temp;
	stack<int> s;
	vector<int> b(n,0);
	s.push(src);
	b[src] =1;

	while(s.empty() != 1)
	{
		ct+=r[s.top()];
		temp = s.top();
		s.pop();

		for (int i = 1; i <= a[temp][0]; ++i)
		{
			if(b[a[temp][i]] == 0)
			{
				s.push(a[temp][i]);
				b[a[temp][i]] = 1;
			}
		}
	}

	return ct;
}

int main()
{
	int t,n,sum,i,j,d,r[100000],count;
	cin>>t;

	while(t--)
	{
		cin>>n;

		for(i=1;i<=n;i++)
			a[i][0]=0;

		for (i = 1; i <= n; ++i)
		{
			cin>>d;
			a[d][0]++;
			a[d][a[d][0]] = i;
		}

		for (i = 1; i <= n; ++i)
			cin>>r[i];

		sum = 0;

		for (i = 1; i <= n; ++i)
		{
			count = dfs(i,n,r);

			if(count > 0 )
				sum+=count;
		}

		cout<<sum<<endl;
	}
	return 0;
}
