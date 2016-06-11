#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
	int n,s,i;
	long long int t,a;
	scanf("%d",&n);
	while(n--)
	{
		s=0;
		scanf("%lld",&t);
		i=1;
	    while(pow(5,i)<=t)
	    {
		    a=t/pow(5,i);
			s+=a;
			i++;
		}
		printf("%d",s);
		printf("\n");
	}
	return 0;
	
}
