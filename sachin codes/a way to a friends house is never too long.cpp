#include<bits/stdc++.h>
using namespace std;
bool compares(const pair<int,int >&i, const pair<int,int >&j)
{
	if(i.first==j.first)
	return i.second>j.second;
	else
    return i.first < j.first;
}
int main()
{
	int t,n,i,x,y,x1,y1,x2,y2;
	double s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<pair<int ,int> >v;
		vector<pair<int ,int> > ::iterator it;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			v.push_back(make_pair(x,y)); 
		}
		sort(v.begin(),v.end(),compares);
		//for(i=0;i<n;i++)
		//printf("%d %d\n",v[i].first,v[i].second);
		s=0;
		for(i=0;i<n-1;i++)
		{
			x1=v[i].first;    y1=v[i].second;
			x2=v[i+1].first;  y2=v[i+1].second;
			s+=sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1)));
		}
		printf("%.2lf\n",s);
	}
	return 0;
}
