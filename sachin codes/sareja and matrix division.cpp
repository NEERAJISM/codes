#include<bits/stdc++.h>
using namespace std;
 
vector<vector<pair<int,int> > > g;
vector<pair<int,int> > ans;
vector<pair<int,pair<int,pair<int,int> > > > res1;
vector<pair<int,pair<int,pair<int,int> > > > res2;
vector<pair<int,pair<int,pair<int,int> > > > res3;
int hash[10002];
 
void function1()
{
	int x,y,x1,y1,x2,y2,flag,i,a,b,c,d,a1,b1,c1,d1,a2,b2,c2,d2,j;
		sort(ans.begin(),ans.end());
		
		x1=ans[0].first;   y1=ans[0].second;
		x=x1;              y=y1;
		flag=0;
		for(i=1;i<ans.size();i++)
		{
			x2=ans[i].first;   y2=ans[i].second;
			if(x2==x&&y2==y+1)
			{
				x=x2;  y=y2;
				flag=0;
			}
			else
			{
				//c++;
				res1.push_back(make_pair(x1,make_pair(y1,make_pair(x,y))));
				x1=x2;   y1=y2;    //cout<<"x1="<<x1<<"y1="<<y1<<endl;
				x=x2;    y=y2;
				flag=1;
				if(i+1==ans.size())
				res1.push_back(make_pair(x1,make_pair(y1,make_pair(x,y))));
			}
		}
		if(flag==0)
		{
			//cout<<"x1="<<x1<<"y1="<<y1<<endl;
			res1.push_back(make_pair(x1,make_pair(y1,make_pair(x,y))));
		}
		sort(res1.begin(),res1.end());
		
		for(i=0;i<10000;i++)
		hash[i]=0;
		
		for(i=0;i<res1.size();i++)
		{
			flag=0;
			if(hash[i]==0)
			{
			
				a1=res1[i].first;   b1=res1[i].second.first;  c1=res1[i].second.second.first;  d1=res1[i].second.second.second;
				a=a1; b=b1;c=c1; d=d1;
				
				for(j=i+1;j<res1.size();j++)
				{
					a2=res1[j].first;   b2=res1[j].second.first;  c2=res1[j].second.second.first;  d2=res1[j].second.second.second;
					if(b2==b&&d2==d&&a2==a+1&&c2==c+1&&hash[j]==0)
					{
						a=a2; c=c2; b=b2; d=d2; hash[j]++;
					}
				}
				res2.push_back(make_pair(a1,make_pair(b1,make_pair(c,d))));
			}
		}
} 
 
int main()
{
	int t,n,m,i,j,num,size,x,y,x1,y1,x2,y2,flag,counter;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		
		g.clear();
		res1.clear();
		res2.clear();
		res3.clear();
		ans.clear();
		
		g.resize(1002);
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&num);
				g[num].push_back(make_pair(i,j));
				//hash[num]++;
			}
		}
		
		for(i=1;i<=1000;i++)
		{
			size=g[i].size() / 2;
			//c+=size;
			sort(g[i].begin(),g[i].end());
			
			for(j=0;j<size;j++)
			{
				ans.push_back(make_pair(g[i][j].first,g[i][j].second));
			}
		}
		function1();
	
			printf("%d\n",res2.size());
			for(i=0;i<res2.size();i++)
			{
				x1=res2[i].first;   y1=res2[i].second.first;  x2=res2[i].second.second.first;  y2=res2[i].second.second.second;
				printf("%d %d %d %d\n",x1,y1,x2,y2);
			}

	}
	return 0;
} 
