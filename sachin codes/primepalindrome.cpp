#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int i;
	long long int n,j;

		scanf("%d",&j);
		
		int a,m=0,c=0;
		do{
		n=j;
		while(n!=0)
		{
			a=n%10;
			n=n/10;
			m=m*10+a;
		}
		
		if(m==j)
		{
			for(i=2;i<=sqrt(m);i++)
			{
				if(m%i==0)
				{
					printf("%d",m);
					printf("\n");
					break;
				}
			}
		}
		j++;
	   }
	   while(m!=j-1);
	
	return 0;
}
