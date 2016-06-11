#include<bits/stdc++.h>
using namespace std;
#define INF 1000000

struct node
{
	long long int sum,lazy;
};

node t[400016];


void merges(int x,int y,int z)
{
	t[z].sum=t[x].sum+t[y].sum;
	t[z].lazy=0;
}

node merge_res(node x,node y,int v)
{
	node temp;
	temp.sum=x.sum+y.sum;
	return temp;
}

void build(long long int a[],int v,int l,int r)
{
	if(l==r)
	{
		t[v].sum=0;
		t[v].lazy=0;
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
	if(t[v].lazy!=0) 
	{
		t[v].sum+=(r-l+1)*t[v].lazy;
		if(l!=r) 
		{
			t[2*v].lazy+=t[v].lazy;
			t[2*v+1].lazy+=t[v].lazy;
		}
		t[v].lazy=0;
	}
	if(x>y)
	{
		node null_node;
		
		null_node.sum=0;
		null_node.lazy=0;
		
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

void update(int v,int l,int r,int x,int y,long long int value)
{
	if(t[v].lazy!=0) 
	{
		t[v].sum+=(r-l+1)*t[v].lazy;
		if(l!=r) 
		{
			t[2*v].lazy+=t[v].lazy;
			t[2*v+1].lazy+=t[v].lazy;
		}
		t[v].lazy=0;
	}
	if(x>y)
	return;
	if(l==x&&r==y)
	{
		t[v].sum+=(y-x+1)*value;
		if(l!=r)
		{
			t[2*v].lazy+=value;
			t[2*v+1].lazy+=value;	
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
	int n,i,x,y,pos,m,l,r,t;
	int id;
	long long int a[100002],value;
	scanf("%d",&t);
	while(t--)
	{
			scanf("%d",&n);
		for(i=0;i<=n;i++)
		a[i]=0;
		build(a,1,0,n-1);
	//	for(i=1;i<=7;i++)
	//	cout<<t[i].sum<<"  ";
		scanf("%d",&m);
		while(m--)
		{
			cin>>id;
			if(id==0)
			{
				scanf("%d%d%lld",&l,&r,&value);
				update(1,0,n-1,l-1,r-1,value);
	        }
	        else
	        {
	        	scanf("%d%d",&x,&y);
	        	node ans;
				ans=query(1,0,n-1,x-1,y-1);
				printf("%lld\n",(ans.sum));
	        }
		}
	}
	return 0;
}
