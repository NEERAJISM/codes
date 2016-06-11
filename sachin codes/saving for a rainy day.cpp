#include<bits/stdc++.h>
using namespace std;
int main()
{
	double M,R,x,M1;
	long long int T;
	scanf("%lf%lld%lf",&M,&T,&R);
	M1=M;
	M=(1200*M)/(1200+R);
	for(int i=1;i<T;i++)
	{
		x=((M+M1)*1200)/(1200+R);
		M=x;
	}
	long long int ans;
	long long int y=(long long int)(x);
	double z=(double)(y);
	if(x-z>.5)
	ans=y+1;
	else
	ans=y;
	printf("%lld\n",ans);
	return 0;
}
