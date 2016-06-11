#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

struct node
{
	int sum,Psum,Ssum,Msum;
};

node t[200005];

void merges(int x,int y,int z)
{
	t[z].sum = t[x].sum+t[y].sum;
	t[z].Psum = max(t[x].Psum , t[x].sum+t[y].Psum);
	t[z].Ssum = max(t[y].Ssum , t[y].sum+t[x].Ssum);
	t[z].Msum = max(t[z].Psum , max(t[z].Ssum , max(t[x].Msum , max(t[y].Msum , t[x].Ssum+t[y].Psum ))));
}

node merge_res(node x,node y)
{
	node temp;
	temp.sum = x.sum+y.sum;
	temp.Psum = max(x.Psum , x.sum+y.Psum);
	temp.Ssum = max(y.Ssum , y.sum+x.Ssum);
	temp.Msum = max(temp.Psum , max(temp.Ssum , max(x.Msum , max(y.Msum , x.Ssum+y.Psum ))));
	return temp;
}

void build(int a[],int v,int l,int r)
{
	if(l==r)
	{
		t[v].sum=a[l];
		t[v].Psum=a[l];
		t[v].Ssum=a[l];
		t[v].Msum=a[l];
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
		
		null_node.sum=0;
		null_node.Psum=-INF;
		null_node.Ssum=-INF;
		null_node.Msum=-INF;
		
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
		t[v].sum=value;
		t[v].Psum=value;
		t[v].Ssum=value;
		t[v].Msum=value;
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
	int n,i,x,y,a[50002],pos,value,m,ans,id;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	build(a,1,0,n-1);
//	for(i=1;i<=7;i++)
//	cout<<t[i].sum<<"  ";
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&id);
		if(id==0)
		{
			scanf("%d%d",&pos,&value);
			update(1,0,n-1,pos-1,value);
        }
        else
        {
        	scanf("%d%d",&x,&y);
        	node ans;
			ans=query(1,0,n-1,x-1,y-1);
			printf("%d\n",ans.Msum);
        }
	}
	return 0;
}
