#include<iostream>
#include<stdio.h>
int main()
{
	int t,n,c,a[100],i,s;
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		scanf("%d%d",&n,&c);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		if(s<=c)
		{
		
		printf("Yes");
		printf("\n");}
		
		else
		{
		
		printf("No");
		printf("\n");}
		
	}
	return 0;
	
}
