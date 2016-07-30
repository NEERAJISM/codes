#include <iostream>
#include <cstdio>
int i,j,a[100005],n,b[10000000];
string s;
using namespace std;

void build_seg_tree(int pos,int low,int high)
{
	if(low==high)
	{
		b[pos] = a[low];
		return;
	}

	int mid = (low+high)/2;

	build_seg_tree(2*pos+1,low,mid);
	build_seg_tree(2*pos+2,mid+1,high);

	b[pos] = b[2*pos+1] + b[2*pos+2];
}


void rangeupdate(int pos,int low,int high,int x,int y,int val)
{
	if(low>high || low > y || high < x )
		return;

	if(low==high)
	{
	    b[pos] += val;
        return;
	}

	int mid = (low+high)/2;

	rangeupdate(2*pos+1,low,mid,x,y,val);
	rangeupdate(2*pos+2,mid+1,high,x,y,val);

	b[pos] = b[2*pos+1]+b[2*pos+2];
}


int rangequery(int pos,int low,int high,int x,int y,int val)
{
	if(low>high || low>y || high<x)
		return 0;

	if(low >=x && high<=y)
	{
		val+=b[pos];
		return val;
	}
	else
	{
		int mid= (low+high)/2;

		val = rangequery(2*pos+1,low,mid,x,y,val)+rangequery(2*pos+2,mid+1,high,x,y,val);
	}
}


int main()
{
    int z0 = (int)'0';

    cin>>s;
    n = s.length();

    for(i=0;i<n;i++)
        a[i] = (int)s[i]-z0;

    build_seg_tree(0,0,n-1);

    cout<<"build\n";
    for(i=0;i<2*n-1;i++)
    	cout<<b[i]<<" ";

    cout<<endl;

    int val,x,y;
    cin>>x>>y>>val;

    rangeupdate(0,0,n-1,x,y,val);

    cout<<"update\n";
    for(i=0;i<2*n-1;i++)
    	cout<<b[i]<<" ";

    cout<<endl;

    cin>>x>>y;
    val= 0;

    cout<<"the sum provided in the given range is:\t"<< rangequery(0,0,n-1,x,y,val);

return 0;
}
