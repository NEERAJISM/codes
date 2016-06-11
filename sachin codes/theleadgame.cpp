#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,a,b,sa=0,sb=0,ca=0,cb=0,ma=0,mb=0;
	
	scanf("%d",&n);
	
	while(n--)
	{
		scanf("%d%d",&a,&b);
		sa+=a;
		sb+=b;
		if(sa>sb)
		{
			ca=sa-sb;
			if(ca>ma)
			ma=ca;
		}
		else
		{
			cb=sb-sa;
			if(cb>mb)
			mb=cb;
		}
	}
	if(ma>mb)
	{
		printf("1");
		printf(" %d",ma);
	}
	else{
		printf("2");
		printf(" %d",mb);
	}

    return 0;
}
