#include<bits/stdc++.h>
using namespace std;

struct node
{
	int sum;
};

node t[400000];

void merges(int x,int y,int z)
{
	t[z].sum=t[x].sum+t[y].sum;
}

node merge_node(node x,node y)
{
	node temp;
	temp.sum=x.sum+y.sum;
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
		nullnode.sum=0;
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
	t[v].sum=val;
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
	int n,m,i,j,x,y,pos,val,id;
	int a[100000];
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	build(a,1,0,n-1);
	
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&id);
		if(id==1)
		{
			scanf("%d%d",&x,&y);
			node ans=query(1,0,n-1,x-1,y-1);
			printf("%d\n",ans.sum);
		}
		else if(id==2)
		{
			scanf("%d%d",&pos,&val);
			update(1,0,n-1,pos-1,val);
		}
	}
	return 0;
}
