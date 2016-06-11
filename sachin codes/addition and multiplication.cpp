#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

struct node
{
	long long int sum,lazy_add,lazy_mul;
};

node t[400016];


void merges(int x,int y,int z)
{
	t[z].sum=(t[x].sum+t[y].sum)%mod;
}

void b_merges(int x,int y,int z)
{
	t[z].sum=(t[x].sum+t[y].sum)%mod;
	t[z].lazy_add=0;
	t[z].lazy_mul=1;
}

node merge_res(node x,node y,int v)
{
	node temp;
	temp.sum=(x.sum+y.sum)%mod;
	return temp;
}

void build(long long int a[],int v,int l,int r)
{
	if(l==r)
	{
		t[v].sum=a[l];
		t[v].lazy_add=0;
		t[v].lazy_mul=1;
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
	if(t[v].lazy_add!=0||t[v].lazy_mul!=1)
	{
		t[v].sum=(t[v].sum*t[v].lazy_mul)%mod;
		t[v].sum=(t[v].sum+((r-l+1)*t[v].lazy_add)%mod)%mod;
		if(l!=r)
		{
			t[2*v].lazy_mul=(t[2*v].lazy_mul*t[v].lazy_mul)%mod;
			t[2*v+1].lazy_mul=(t[2*v+1].lazy_mul*t[v].lazy_mul)%mod;
			t[2*v].lazy_add=(t[2*v].lazy_add*t[v].lazy_mul)%mod;
			t[2*v+1].lazy_add=(t[2*v+1].lazy_add*t[v].lazy_mul)%mod;

			t[2*v].lazy_add=(t[2*v].lazy_add+t[v].lazy_add)%mod;
			t[2*v+1].lazy_add=(t[2*v+1].lazy_add+t[v].lazy_add)%mod;
		}
		t[v].lazy_mul=1;
		t[v].lazy_add=0;
	}
	if(x>y)
	{
		node null_node;

		null_node.sum=0;
		null_node.lazy_add=0;
		null_node.lazy_mul=1;

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

void update_add(int v,int l,int r,int x,int y,long long int value)
{
	if(t[v].lazy_add!=0||t[v].lazy_mul!=1)
	{
		t[v].sum=(t[v].sum*t[v].lazy_mul)%mod;
		t[v].sum=(t[v].sum+((r-l+1)*t[v].lazy_add)%mod)%mod;
		if(l!=r)
		{
			t[2*v].lazy_mul=(t[2*v].lazy_mul*t[v].lazy_mul)%mod;
			t[2*v+1].lazy_mul=(t[2*v+1].lazy_mul*t[v].lazy_mul)%mod;
			t[2*v].lazy_add=(t[2*v].lazy_add*t[v].lazy_mul)%mod;
			t[2*v+1].lazy_add=(t[2*v+1].lazy_add*t[v].lazy_mul)%mod;

			t[2*v].lazy_add=(t[2*v].lazy_add+t[v].lazy_add)%mod;
			t[2*v+1].lazy_add=(t[2*v+1].lazy_add+t[v].lazy_add)%mod;
		}
		t[v].lazy_mul=1;
		t[v].lazy_add=0;
	}
	if(x>y)
	return;
	if(l==x&&r==y)
	{
		t[v].sum=(t[v].sum+((y-x+1)*value)%mod)%mod;
		if(l!=r)
		{
			t[2*v].lazy_add=(t[2*v].lazy_add+value)%mod;
			t[2*v+1].lazy_add=(t[2*v+1].lazy_add+value)%mod;
		}
	}
	else
	{
		int m=(l+r)/2;

		update_add(2*v,l,m,x,min(m,y),value);

		update_add(2*v+1,m+1,r,max(x,m+1),y,value);

		merges(2*v,2*v+1,v);
	}
}

void update_mul(int v,int l,int r,int x,int y,long long int value)
{
	if(t[v].lazy_add!=0||t[v].lazy_mul!=1)
	{
		t[v].sum=(t[v].sum*t[v].lazy_mul)%mod;
		t[v].sum=(t[v].sum+((r-l+1)*t[v].lazy_add)%mod)%mod;
		if(l!=r)
		{
			t[2*v].lazy_mul=(t[2*v].lazy_mul*t[v].lazy_mul)%mod;
			t[2*v+1].lazy_mul=(t[2*v+1].lazy_mul*t[v].lazy_mul)%mod;
			t[2*v].lazy_add=(t[2*v].lazy_add*t[v].lazy_mul)%mod;
			t[2*v+1].lazy_add=(t[2*v+1].lazy_add*t[v].lazy_mul)%mod;

			t[2*v].lazy_add=(t[2*v].lazy_add+t[v].lazy_add)%mod;
			t[2*v+1].lazy_add=(t[2*v+1].lazy_add+t[v].lazy_add)%mod;
		}
		t[v].lazy_mul=1;
		t[v].lazy_add=0;
	}
	if(x>y)
	return;
	if(l==x&&r==y)
	{
		t[v].sum=(t[v].sum*value)%mod;
		if(l!=r)
		{
			t[2*v].lazy_mul=(t[2*v].lazy_mul*value)%mod;
			t[2*v+1].lazy_mul=(t[2*v+1].lazy_mul*value)%mod;
			t[2*v].lazy_add=(t[2*v].lazy_add*value)%mod;
			t[2*v+1].lazy_add=(t[2*v+1].lazy_add*value)%mod;
		}
	}
	else
	{
		int m=(l+r)/2;

		update_mul(2*v,l,m,x,min(m,y),value);

		update_mul(2*v+1,m+1,r,max(x,m+1),y,value);

		merges(2*v,2*v+1,v);
	}
}
int main()
{
	int n,i,x,y,pos,q,l,r,t;
	int id;
	long long int a[100002],value;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	build(a,1,0,n-1);

	while(q--)
	{
		cin>>id;
		if(id==1)
		{
			scanf("%d%d%lld",&l,&r,&value);
			update_add(1,0,n-1,l-1,r-1,value);
	    }
	    else if(id==2)
		{
			scanf("%d%d%lld",&l,&r,&value);
			update_mul(1,0,n-1,l-1,r-1,value);
	    }
	    else if(id==3)
		{
			scanf("%d%d%lld",&l,&r,&value);
			update_mul(1,0,n-1,l-1,r-1,0);
			update_add(1,0,n-1,l-1,r-1,value);
	    }
	    else
	    {
	        scanf("%d%d",&x,&y);
	        node ans;
			ans=query(1,0,n-1,x-1,y-1);
			printf("%lld\n",(ans.sum));
	    }
	}
	return 0;
}
