#include<bits/stdc++.h>
using namespace std;
#define MAXN 100003

//vector<int> t[4*MAXN];
vector<vector<pair<int,int> > > t(4*MAXN);

int func(vector<pair<int,int> > &a,int l,int r)
{
	int x,d,fd=0,ymin,ymax;
	x=a[0].first;        ymin=a[0].second;        ymax=a[0].second;
	//for(i=l;i<=r;i++)
	//cout<<a[i].first<<"   "<<a[i].second<<endl;
	for(int i=1;i<a.size();i++)
	{
		if(a[i].first==x)
		{
			if(a[i].second<ymin)
			ymin=a[i].second;
			if(a[i].second>ymax)
			ymax=a[i].second;
		}
		else
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

void merges(int x,int y,int z)
{
	/*for(int i=0;i<t[x].size();i++)
	t[z].push_back(t[x][i]);
	for(int i=0;i<t[y].size();i++)
	t[z].push_back(t[y][i]);*/
	
	int i=0,j=0,k=0;
	while(i<t[x].size()&&j<t[y].size())
	{
		if(t[x][i].first<t[y][j].first)
		{
			t[z].push_back(make_pair(t[x][i].first,t[x][i].second));
			i++;
		}
		else
		{
			t[z].push_back(make_pair(t[y][j].first,t[y][j].second));
			j++;
		}
	}
	while(i<t[x].size())
	{
		t[z].push_back(make_pair(t[x][i].first,t[x][i].second));
		i++;
	}
	while(j<t[y].size())
	{
		t[z].push_back(make_pair(t[y][j].first,t[y][j].second));
		j++;
	}
}

void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v].push_back(make_pair(a[tl],tl));
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		merges (2*v,2*v+1,v);
	}
}
int query (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;                       //cout<<"hello";
	if (l == tl && tr == r) {
	      int ans=func(t[v],tl,tr);//cout<<"ans="<<ans<<endl;
	      return ans;
	}
	int tm = (tl + tr) / 2;
	return max(
		query (v*2, tl, tm, l, min(r,tm)),query (v*2+1, tm+1, tr, max(l,tm+1), r)
	);
}

int main()
{
	int n,q,i,j,l,r,ans,k,m;
	char s[100003];
	int a[100003];
	

		scanf("%d%d%d",&n,&m,&q);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		build(a,1,0,n-1);
		while(q--)
		{
			scanf("%d%d",&l,&r);
			ans=query(1,0,n-1,l-1,r-1);
			printf("%d\n",ans);
		}
	return 0;
}
