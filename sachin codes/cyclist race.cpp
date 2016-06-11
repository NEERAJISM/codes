#include<bits/stdc++.h>
using namespace std;

struct node
{
	int maxi;
};

node t[400000];
speed sp[50005];

void merges(int x,int y,int z)
{
	t[z].maxi=t[x].maxi+t[y].maxi;
}

node merge_node(node x,node y)
{
	node temp;
	temp.maxi=x.maxi+y.maxi;
	return temp;
}

void build(int a[],int v,int l,int r)
{
	if(l==r)
	{
		t[v].sum=a[l];
	}
	else
	{
		int m=(l+r)/2;
		build(a,2*v,l,m);
		build(a,2*v+1,m+1,r);
		merges(2*v,2*v+1,v);
	}
}

node query(int v,int l,int r,int x,int y)
{
	if(x>y)
	{
		node nullnode;
		nullnode.maxi=0;
		return nullnode;
	}
	else if (l==x&&r==y)
	return t[v];
	else
	{
		int m=(l+r)/2;
		node n1=query(2*v,l,m,x,min(m,y));
		node n2=query(2*v+1,m+1,r,max(m+1,x),y);
		node temp=merge_node(n1,n2);
		return temp;
	}
}

void update(int v,int l,int r,int pos,int val)
{
	if(l==r)
	t[v].maxi=val;
	else
	{
		int m=(l+r)/2;
		if(pos<=m)
		update(2*v,l,m,pos,val);
		else
		update(2*v+1,m+1,r,pos,val);
		
		merges(2*v,2*v+1,v);
	}
}

int main()
{
	int n,m,i,j,id,pos;
	long long int a[50005];
	long long int t,prev,val;
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++)
	{
		sp[i]=0;  a[i]=0;
	}
	
	build(a,1,0,n-1);
	
	prev=0;
	while(m--)
	{
		scanf("%d",&id);
		if(id==1)
		{
			scanf("%lld%d%lld",&t,&pos,&val);
			update(1,0,n-1,pos-1,val);
		}
		else if(id==2)
		{
			scanf("%lld",&t);
			node ans=query(1,0,n-1,x-1,y-1);
			printf("%lld\n",ans.sum);
		}
	}
	return 0;
}
