#include<iostream>
#include<stdio.h>
using namespace std;

int BinarySearch(string A[], int l, int r, string key)
{
    int m;
 
    while( l <= r )
    {
        m = l + (r-l)/2;
 
        if( A[m] == key ) // first comparison
            return m;
 
        if( A[m] < key ) // second comparison
            l = m + 1;
        else
            r = m - 1;
    }
 
    return -1;
}


int main()
{
	int t,i,x,n;
	string s[1003],s1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			cin>>s[i];
		}
		cin>>s1;
		x=BinarySearch(s,0,n-1,s1);
		if(x==-1)
		printf("no\n");
		else
		printf("yes\n");
	}	
	return 0;
}
