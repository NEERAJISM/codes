#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

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

long long int func(long long int x,long long int n,long long int k)
{
	long long int i,a,sum1=0,sum2=0,sum;
	for(i=x+2;i<=n;i++)
	{
		a=modular_exponentiation(k,i,M);
		a=(a*(i-x-1))%M;
		sum1=(sum1+a)%M;
	}
	for(i=2;i<=n-x;i++)
	{
		a=modular_exponentiation(k,i,M);
		a=(a*(i-1))%M;
		sum2=(sum2+a)%M;
	}
	sum=sum1-sum2;
	if(sum<0)
	sum=sum+M;
	
	return sum;
}

int main()
{
	int t;
	long long int sum1,sum2,x,n,i,r,d,k,y,ans,z,a,b,c,S1,S2,S,d1,d2,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		
		sum1=0;
		for(i=1;i<n;i++)
		{
			a=modular_exponentiation(k,n+1,M);
			b=modular_exponentiation(k,i+1,M);
			c=modular_exponentiation(k,n-i+1,M);
			c=k-c;
			if(c<0)
			c=c+M;
			
			x=(a-b+c);
			if(x<0)
			x=x+M;
			
			y=(a-b+2*c);
			if(y<0)
			y=y+M;
			
			z=modular_exponentiation(k-1,M-2,M);
			
			x=(x*z)%M;
			if(x<1)
			x=x+M;
			
			y=(y*z)%M;
			
			d=modular_exponentiation(k,i,M);
			if(d<1)
			d=d+M;
			
			p=func(i,n,k);
			
			S1=(x*(x-1))%M;
			S1=(S1*3)%M;
			S1=(S1-(6*p));
			if(S1<0)
			S1=S1+M;
			S1=(S1*d)%M;
			//cout<<"S1="<<S1<<endl;
			S2=(y*(d))%M;
			S2=(S2*(d-1))%M;
			S2=(S2*(3))%M;//cout<<"d="<<d<<endl;
		//cout<<"S2="<<S2<<endl;
			sum1=(sum1+S1+S2)%M;
		}
	
		sum2=0;
		for(i=1;i<=n;i++)
		{
			d2=modular_exponentiation(k,i,M);
			if(d2<2)
			d2=d2+M;
			
			S=(d2*(d2-1))%M;
			S=(S*(d2-2))%M;
			
			sum2=(sum2+S)%M;
		}
	
		ans=(sum1+sum2)%M;
		
		printf("%lld\n",ans);
	}
	return 0;
}
