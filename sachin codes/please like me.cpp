#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	long long int i,l,d,s,c,curr,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&l,&d,&s,&c);
		int flag=0;
		for(i=0;i<d;i++)
		{
			p=pow((c+1),i);
			curr=s*p;
			if(curr>=l)
			{
				flag++;
				break;
			}
		}
		if(flag==0)
		printf("DEAD AND ROTTING\n");
		else 
		printf("ALIVE AND KICKING\n");
	}
	return 0;
}
