#include<bits/stdc++.h>
using namespace std;

long long int modular_exponentiation(long long int a,long long int b)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y);      //  or call  mulmod(x,y,c);
		}
		y=(y*y);          //  or call  mulmod(y,y,c);
		b=b/2;
	}
	return x;
}


int main()
{
	int t,s,c,k,i,x;
	long long int y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&s,&c,&k);
		if(c==0)
		{
			if(k<=s)
			{
				x=s-k+1;
				y=modular_exponentiation(2,x);
				printf("%lld\n",y+1);
			}
			else
			printf("0\n");
		}
		else if(s==0)
		{
			if(k==1)
			{
				x=c+1;
					y=modular_exponentiation(2,x);
				printf("%lld\n",y-2);
			}
			else
			printf("0\n");
		}
		else if(c!=0&&s!=0&&k==1)
		{
			if(s>c)
			{
				x=s-k+1;
				y=modular_exponentiation(2,x);
				printf("%lld\n",y+1);
			}
			else
			{
				x=c+1;
				z=modular_exponentiation(2,x);
				y=z+1;
				printf("%lld\n",y);
			}
		}                                                      
		else if(c!=0&&s!=0&&k>1)
		{
			if(k>s+c)
			printf("0\n");
			else
			{
					if(k>s)
					printf("0\n");
					else
					{
						if(c>=s-1)
						{
							x=s-k+2;
							y=modular_exponentiation(2,x);
							printf("%lld\n",y+1);
						}
						else
						{
							if(k>s-c)
							{
								x=s-k+2;
								y=modular_exponentiation(2,x);
								printf("%lld\n",y+1);
							}
							else
							{
								x=s-k+2;
								y=modular_exponentiation(2,x);
								y=y+1;
								x=s-k+1;
								z=modular_exponentiation(2,x);
								printf("%lld\n",(y-z));
							}
						}
					}
			}
		}
	}
	return 0;
}
