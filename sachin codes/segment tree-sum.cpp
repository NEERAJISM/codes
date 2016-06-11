#include<bits/stdc++.h>
using namespace std;

int t[100];

void build(int a[],int v,int l,int r)
{
	if(l==r)
	t[v]=a[l];
	else
	{
		int m=(l+r)/2;
		build(a,2*v,l,m);
		build(a,2*v+1,m+1,r);
		t[v]=t[2*v]+t[2*v+1];
	}
} 

int query(int v,int l,int r,int x,int y)
{
	if(x>y)
	return 0;
	else if(l==x&&r==y)
	return t[v];
	else
	{
		int m=(l+r)/2;
		return(query(2*v,l,m,x,min(m,y))+query(2*v+1,m+1,r,max(x,m+1),y));
	}
}

void update(int v,int l,int r,int pos,int value)
{
	if(l==r)
	t[v]=value;
	else
	{
		int m=(l+r)/2;
		if(pos<=m)
		update(2*v,l,m,pos,value);
		else
		update(2*v+1,m+1,r,pos,value);
		t[v]=t[2*v]+t[2*v+1];
	}
}

int main()
{
	int n,i,x,y,a[20],pos,value;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	build(a,1,0,n-1);
	cout<<"enter the pos and value\n";
	cin>>pos>>value;
	update(1,0,n-1,pos,value);
	cout<<"enter the range\n";                //   min x=0     max y= n-1
	scanf("%d%d",&x,&y);
	cout<<"sum is = "<<query(1,0,n-1,x,y);
	return 0;
}
