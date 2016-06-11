#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > a;

int func(int l,int r)
{
		int x,d,fd=0,ymin,ymax,j;
		
		for(int i=0;i<a.size();i++)
		{
			if(a[i].second>=l&&a[i].second<=r)
			{
				x=a[i].first;        ymin=a[i].second;        ymax=a[i].second;
				j=i;
				break;
			}
		}
	
	for(int i=j+1;i<a.size();i++)
	{
		if(a[i].first==x&&a[i].second>=l&&a[i].second<=r)
		{
			if(a[i].second<ymin)
			ymin=a[i].second;
			if(a[i].second>ymax)
			ymax=a[i].second;
		}
		else if(a[i].first!=x&&a[i].second>=l&&a[i].second<=r)
		{
			d=ymax-ymin;      //cout<<"i="<<i<<"a[i]="<<a[i].first<<"ymax="<<ymax<<"ymin="<<ymin<<"fd="<<fd<<"d="<<d<<endl;
			if(d>fd)
			fd=d;   
			x=a[i].first;       ymin=a[i].second;        ymax=a[i].second;
		}
	}
	d=ymax-ymin;
	if(d>fd)
	fd=d;
	return fd;
}

int main()
{
	int n,q,i,j,l,r,ans,k,m,x;
	

		scanf("%d%d%d",&n,&m,&q);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a.push_back(make_pair(x,i));
		}
		sort(a.begin(),a.end());
		//for(i=0;i<n;i++)
		//cout<<a[i].first<<"   "<<a[i].second<<endl;
		while(q--)
		{
			scanf("%d%d",&l,&r);
			ans=func(l-1,r-1);
			printf("%d\n",ans);
		}
	return 0;
}
