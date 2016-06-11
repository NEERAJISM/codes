#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long int n,x,q;
	int m,p;
	scanf("%lld%d",&n,&m);
	while(m--)
	{
		scanf("%lld",&x);
		p=x/n;
		q=x%n;
		if(p==0||p==4)
		printf("0\n");
		else if(p==1&&q<2)
		printf("0\n");
		else if(p==1&&q>=2)
		printf("%d\n",(x-n-1));
		else if(p==2&&q<=1)
		printf("%d\n",(x-n-1));
		else if(p==2&&q>=2)
		printf("%d\n",(3*n+1-x));
		else if(p==3&&q==0)
		printf("%d\n",(3*n+1-x));
		else if(p==3&&q>=1)
		printf("0\n");
	}
	return 0;
}
