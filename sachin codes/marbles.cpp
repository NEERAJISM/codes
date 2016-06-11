#include<cstdio>
#include<algorithm>
using namespace std;
long long int ncr(int v,int b)
{
	long long int r,k,i;
	r=min(b,v-b);
	if(r==0)
	return 1;
	return ncr(v-1,r-1) * v / r;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(k==1)
		printf("1\n");
		else
		{
		long long int sum;
		sum=ncr(n-1,k-1);
		printf("%lld\n",sum);
		}
	}
	return 0;
} 
