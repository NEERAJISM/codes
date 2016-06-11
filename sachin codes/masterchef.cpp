#include<bits/stdc++.h>
using namespace std;
#define inf 501

long long int a[100002];
int minimum[100002];
vector<pair<long long int,int> > b;
long long int dp[100002][502];

struct node
{
	int mini,lazy;
};

node t[400016];


void merges(int x,int y,int z)
{
	t[z].mini=min(t[x].mini,t[y].mini);
}
void b_merges(int x,int y,int z)
{
	t[z].mini=min(t[x].mini,t[y].mini);
	t[z].lazy=501;
}

node merge_res(node x,node y,int v)
{
	node temp;
	temp.mini=min(x.mini,y.mini);
	return temp;
}

void build(int a[],int v,int l,int r)
{
	if(l==r)
	{
		t[v].mini=a[l];
		t[v].lazy=501;
	}
	else
	{
		int m=(l+r)/2;
		build(a,2*v,l,m);
		build(a,2*v+1,m+1,r);
		b_merges(2*v,2*v+1,v);
	}
} 

node query(int v,int l,int r,int x,int y)
{
	if(t[v].lazy!=501) 
	{
		t[v].mini=min(t[v].mini,t[v].lazy);
		if(l!=r) 
		{
			t[2*v].lazy=min(t[2*v].lazy,t[v].lazy);
			t[2*v+1].lazy=min(t[2*v+1].lazy,t[v].lazy);
		}
		t[v].lazy=501;
	}
	if(x>y)
	{
		node null_node;
		
		null_node.mini=501;
		null_node.lazy=501;
		
		return null_node;
	}
	if(l==x&&r==y)
	return t[v];
	else
	{
		int m=(l+r)/2;
		node n1=query(2*v,l,m,x,min(m,y));
		node n2=query(2*v+1,m+1,r,max(x,m+1),y);
		node temp1;
		temp1=merge_res(n1,n2,v);
		return temp1;
	}
}

void update(int v,int l,int r,int x,int y,int value)
{
	if(t[v].lazy!=501) 
	{
		t[v].mini=min(t[v].mini,t[v].lazy);
		if(l!=r) 
		{
			t[2*v].lazy=min(t[2*v].lazy,t[v].lazy);
			t[2*v+1].lazy=min(t[2*v+1].lazy,t[v].lazy);
		}
		t[v].lazy=501;
	}
	if(x>y)
	return;
	if(l==x&&r==y)
	{
		t[v].mini=min(t[v].mini,value);//cout<<"t="<<t[v].mini<<endl;
		if(l!=r)
		{
			t[2*v].lazy=min(t[2*v].lazy,value);
			t[2*v+1].lazy=min(t[2*v+1].lazy,value);	
		}
	}
	else
	{
		int m=(l+r)/2;
	
		update(2*v,l,m,x,min(m,y),value);
		
		update(2*v+1,m+1,r,max(x,m+1),y,value);
		
		merges(2*v,2*v+1,v);
	}
}


int main()
{
	int t,n,m,k,i,j,x,l,r,c;
	long long int sum,ans;
	scanf("%d",&t);
	while(t--)
	{
		b.clear();
 
		scanf("%d%d%d",&n,&k,&m);
		
		for(i=0;i<=n;i++)
		minimum[i]=inf;
		build(minimum,1,0,n-1);
		
		b.push_back(make_pair(0,0));
		
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
			if(a[i]<0)
			{
				b.push_back(make_pair(-a[i],i));
			}
		}
		
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&l,&r,&c);
			update(1,0,n-1,l-1,r-1,c);
		}
		for(i=1;i<=n;i++)
		{
			node ans1;
			ans1=query(1,0,n-1,i-1,i-1);
			//cout<<ans.mini<<"   ";
			minimum[i]=ans1.mini;
		}
//		for(i=1;i<=n;i++)
//		cout<<minimum[i]<<"  ";
//		cout<<endl;
 
		for(i=0;i<b.size();i++)
		{
			for(j=0;j<=k;j++)
			{
				dp[i][j]=0;
			}
		}
		
		for(i=0;i<b.size();i++)
		{
			for(j=0;j<=k;j++)
			{
				if(i==0||j==0)
				dp[i][j]=0;
				else if(minimum[b[i].second]<=j)
				dp[i][j]=max(b[i].first+dp[i-1][j-minimum[b[i].second]] , dp[i-1][j]);
				else
				dp[i][j]=dp[i-1][j];
			}
		}
		
		
		ans=sum+dp[b.size()-1][k];
		printf("%lld\n",ans);
	}
	return 0;
} 
