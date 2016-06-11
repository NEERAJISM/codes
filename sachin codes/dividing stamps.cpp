#include<iostream>
#include<stdio.h>
using namespace std;
int a[100000];
int main()
{
	int t,n,i,s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	    s+=a[i];
	}
	t=(n*(n+1))/2;
	if(s==t)
	printf("YES\n");
	else
	printf("NO\n");
}
