#include<bits/stdc++.h>
using namespace std;
#define M 1000000007;

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

long long int a[100003],sum[100003],x,y,z,s,s1,p[100003];

int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		scanf("%lld",&a[i]);
		
		p[0]=1;
		for(i=1;i<=n;i++)
		p[i]=(p[i-1]*2)%M;
		
		for(i=2;i<=n;i++)
		{
			 
			if(i==2)
			{
				s1=(a[2]*a[1]*2)%M; //cout<<"i="<<i<<"s1="<<s1<<endl;
			}
			else
			{
				x=modular_exponentiation(a[i-1],1000000005,1000000007);
				y=(s1*x)%M;
				y=(y*a[i])%M;
				x=(a[i]*a[i-1])%M;
				z=(x*p[i-1])%M;
				s1=(y+z)%M;
			}
			
			s=0;
			x=(a[i]*a[0])%M;  
			y=(x*2)%M;       
			s=(s+y+s1)%M;
			
			sum[i]=s;
		}
		sum[1]=(a[1]*a[0]*2)%M;
		
		long long int ans=0;
		for(i=1;i<=n;i++)
		{
			x=(sum[i]*p[n-i])%M; 
			ans=(ans+x)%M;
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
