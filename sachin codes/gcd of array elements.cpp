#include<iostream>
#include<stdio.h>
using namespace std;

int gcd(int p,int q)
{
	if(q==0)
    return p;
	else
	return gcd(q,p%q);
}

int a[100002];
int main()
{
	    int n,i,x;
     	scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		x=gcd(a[0],a[1]);
		i=2;
		
		while(i<n)
		{
			x=gcd(a[i],x);
			i++;
		}
		cout<<"gcd of all array elements = "<<x;
		return 0;
}
