#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t,p,s,i,x;
	scanf("%d",&t);
	while(t--)
	{
		s=0;i=11;
		scanf("%d",&p);
		while(p!=0)
		{
			x=pow(2,i);
			s+=p/x;
			p=p%x;
			i--;
		}
		printf("%d",s);
		printf("\n");
	}
	return 0;
}
