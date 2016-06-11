#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int t;
	int n,m,p,count,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		count=0;
		for(i=1;i<=m;i++)
		{
			if(gcd(i,n)==1)
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
