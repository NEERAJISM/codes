#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(360%n==0)
		printf("y ");
		else
		printf("n ");
		if(n<=360)
		printf("y ");
		else
		printf("n ");
		if(n<=26)
		printf("y ");
		else
		printf("n ");
		printf("\n");

	}
	return 0;
}
