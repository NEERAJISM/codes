#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

struct node
{
	int fmax,smax;
};

node t[400016];

void merges(int x,int y,int z)
{
	t[z].fmax=max(t[x].fmax,t[y].fmax);
	if(t[z].fmax==t[x].fmax)
	t[z].smax=max(t[x].smax,t[y].fmax);
	else if(t[z].fmax==t[y].fmax)
	t[z].smax=max(t[y].smax,t[x].fmax);
}

node merge_res(node x,node y)
{
	node temp;
	
	temp.fmax=max(x.fmax,y.fmax);
	if(temp.fmax==x.fmax)
	temp.smax=max(x.smax,y.fmax);
	else if(temp.fmax==y.fmax)
	temp.smax=max(y.smax,x.fmax);
	
	return temp;
}

void build(int a[],int v,int l,int r)
{
	if(l==r)
	{
		t[v].fmax=a[l];
		t[v].smax=0;
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
		node null_node;
		
		null_node.fmax=0;
		null_node.smax=0;
		
		return null_node;
	}
	else if(l==x&&r==y)
	return t[v];
	else
	{
		int m=(l+r)/2;
		node n1=query(2*v,l,m,x,min(m,y));
		node n2=query(2*v+1,m+1,r,max(x,m+1),y);
		node temp1;
		temp1=merge_res(n1,n2);
		return temp1;
	}
}

void update(int v,int l,int r,int pos,int value)
{
	if(l==r)
	{
		t[v].fmax=value;
		t[v].smax=0;
	}
	else
	{
		int m=(l+r)/2;
		if(pos<=m)
		update(2*v,l,m,pos,value);
		else
		update(2*v+1,m+1,r,pos,value);
		
		merges(2*v,2*v+1,v);
	}
}

int main()
{
	int n,i,x,y,a[100002],pos,value,m,ans;
	char id;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	build(a,1,0,n-1);
//	for(i=1;i<=7;i++)
//	cout<<t[i].sum<<"  ";
	scanf("%d",&m);
	while(m--)
	{
		cin>>id;
		if(id=='U')
		{
			scanf("%d%d",&pos,&value);
			update(1,0,n-1,pos-1,value);
        }
        else
        {
        	scanf("%d%d",&x,&y);
        	node ans;
			ans=query(1,0,n-1,x-1,y-1);
			printf("%d\n",(ans.fmax+ans.smax));
        }
	}
	return 0;
}
