#include<iostream>
#include<stdio.h>
using namespace std;

// Returns location of key, or -1 if not found
int BinarySearch(int A[], int l, int r, int key)
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
	int n,i,pos,x,A[100000];
	cout<<"enter the size\n";
	cin>>n;
	cout<<"enter the elements\n";
	for(i=0;i<n;i++)
	cin>>A[i];
	cout<<"enter the element to search\n";
	cin>>x;
	pos=BinarySearch(A,0,n-1,x);
	if(pos==-1)
	cout<<"element not fount";
	else
	cout<<"element found at i= "<<pos;
	return 0;
	
	
}
