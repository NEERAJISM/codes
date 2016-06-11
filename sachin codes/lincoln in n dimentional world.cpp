#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long int fact[1000003];

long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y)%c;      //  or call  mulmod(x,y,c);
		}
		y=(y*y)%c;          //  or call  mulmod(y,y,c);
		b=b/2;
	}
	return x%c;
}

int main()
{
	int t,n,m;
	long long int x,y,yy,z,ans;
	
	fact[0]=1;
	for(int i=1;i<=1000001;i++)
	fact[i]=(fact[i-1]*i)%MOD;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ans=1;
		x=fact[n*(m-1)];  //cout<<"x="<<x<<endl;
		y=fact[m-1];     //cout<<"y="<<y<<endl;
		yy=modular_exponentiation(y,n,MOD);
		z=modular_exponentiation(yy,MOD-2,MOD);
		ans=(x*z)%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
