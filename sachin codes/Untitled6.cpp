#include<bits/stdc++.h>
using namespace std;
#define INF 1000000

struct node
{
	long long int mini,lazy;
};

node t[400016];


void merges(int x,int y,int z)
{
	t[z].mini=min(t[x].mini,t[y].mini);
}
void b_merges(int x,int y,int z)
{
	t[z].mini=min(t[x].mini,t[y].mini);
	t[z].lazy=201;
}

node merge_res(node x,node y,int v)
{
	node temp;
	temp.mini=min(x.mini,y.mini);
	return temp;
}

void build(long long int a[],int v,int l,int r)
{
	if(l==r)
	{
		t[v].mini=a[l];
		t[v].lazy=201;
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
	if(t[v].lazy<t[v].mini) 
	{
		t[v].mini=min(t[v].mini,t[v].lazy);
		if(l!=r) 
		{
			t[2*v].lazy=min(t[2*v].lazy,t[v].lazy);
			t[2*v+1].lazy=min(t[2*v+1].lazy,t[v].lazy);
		}
		t[v].lazy=t[v].mini;
	}
	if(x>y)
	{
		node null_node;
		
		null_node.mini=201;
		null_node.lazy=201;
		
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
	if(t[v].lazy<t[v].mini) 
	{
		t[v].mini=min(t[v].mini,t[v].lazy);
		if(l!=r) 
		{
			t[2*v].lazy=min(t[2*v].lazy,t[v].lazy);
			t[2*v+1].lazy=min(t[2*v+1].lazy,t[v].lazy);
		}
		t[v].lazy=t[v].mini;
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
	int n,i,x,y,pos,m,l,r,T;
	int id;
	long long int a[100002],c;
	scanf("%d",&T);
	while(T--)
	{
			scanf("%d",&n);
		for(i=0;i<=n;i++)
		a[i]=201;
		build(a,1,0,n-1);
	//	for(i=1;i<=7;i++)
	//	cout<<t[i].sum<<"  ";
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d%lld",&l,&r,&c);
			//node ans;
			//ans=query(1,0,n-1,l-1,r-1);
			//if(c<ans.min)
			
			update(1,0,n-1,l-1,r-1,c);
		}
		for(i=0;i<n;i++)
		{
			node ans;
			ans=query(1,0,n-1,i,i);
			cout<<ans.mini<<"  ";
		}
		//for(i=1;i<6;i++)
		//cout<<t[i].mini<<"   ";
	}
	return 0;
}
