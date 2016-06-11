#include<iostream>
#include<stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==0)
		{
		printf("0");
		printf("\n");}
		else
		{
			printf("%d",(n/2)+1);
			printf("\n");
		}
	}
	return 0;
}
