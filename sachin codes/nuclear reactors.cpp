#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int A,n,k,a[100]={0},i;
	scanf("%d%d%d",&A,&n,&k);
	
	for(i=0;i<k;i++)
	{
		a[i]=A%(n+1);
		A=A/(n+1);
	}
	
	for(i=0;i<k;i++)
	printf("%d ",a[i]);
	
	printf("\n");
	return 0;
}
