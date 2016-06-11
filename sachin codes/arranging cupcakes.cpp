#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t,n,i,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a=int(sqrt(n));
		for(i=a;i>=1;i--)
		{
			if(n%i==0)
			{
			
			b=i;
			break;}
		}
		c=n/b;
		printf("%d\n",c-b);
	}
	return 0;
}
