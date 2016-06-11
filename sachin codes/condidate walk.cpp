#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n;
	long long int s,i,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		s=0;
		if(n==1)
		{
			s=(d)*(d-1)*((2*d)-1);
			s=s/6;
			printf("%lld\n",s);
		}
		else if(n==2)
		{
			s=0;
			for(i=2;i<=d;i++)
			{
				s+=(((2*i)-3)*((i-1)^(i-2)));
			}
			printf("%lld\n",s);
		}
		else
		printf("%lld\n",s);
	}
	return 0;
}
