#include<bits/stdc++.h>
#define M 1000000007
using namespace std;

long long int a[100003],diff[100003],sum[100003];

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
{	//cout<<"hello";
	long long int t,n,j,i,x,y,z,ans,f;

	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		
		sort(a+1,a+n+1);
		//for(i=1;i<=n;i++)
		//cout<<a[i]<<"  ";
		
		x=n/2;
		for(i=1;i<=x;i++)
		{
			diff[i]=a[n-i+1]-a[i];
		}

		sum[0]=0;
		for(i=1;i<=x;i++)
		{
			sum[i]=(sum[i-1]+diff[i])%M;
		}
		for(i=n-1;i>x;i--)
		{
			sum[i]=sum[n-i];
		}
			//	for(i=1;i<=n-1;i++)
		//cout<<sum[i]<<" ";
		//cout<<endl;
		ans=0; f=2;
		for(i=1;i<=n-1;i++)
		{
			y=modular_exponentiation(f,i-1,M);
			z=(y*sum[i])%M;
			ans=(ans+z)%M;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
