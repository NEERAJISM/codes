#include<bits/stdc++.h>
using namespace std;
long long int MOD=215372682525;
long long int SS=71814758400;

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
	long long int T,n,m,a,d,x,i,j,count,flag;
	long long int p,q,r,s,sum,t,v1,v2,v,u,qq;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a,&d,&n,&x);
		if(x==0)
		{
			/*p=((n+1)*a)%MOD;
			if(n%2==0)
			{
				m=n/2;
				q=(m*(n-1))%MOD;
			}
			else
			{
				m=(n-1)/2;
				q=(m*n)%MOD;
			}
			
			q=(q*d)%MOD;
			
			sum=(p+q)%MOD;
			printf("%lld\n",sum);*/
			printf("0\n");
			
		}
		else
		{
			p=modular_exponentiation(x,n+1,MOD);//cout<<p<<" ";
			p=p-1;//cout<<p<<" ";
			if(p<0)
			p=p+MOD;//cout<<p<<" ";
			p=(p*a)%MOD;//cout<<p<<" ";
			//qq=modular_exponentiation(x-1,SS,MOD);
			q=modular_exponentiation(x-1,SS-1,MOD);//cout<<q<<" ";
			u=(p*q)%MOD;//cout<<u<<" ";
		
			r=(n*d)%MOD;//cout<<r<<" ";
			r=-r;//cout<<r<<" ";
			r=r+MOD;//cout<<r<<" ";
			v1=(r*q)%MOD;//cout<<v1<<" ";
		
			p=modular_exponentiation(x,n,MOD);//cout<<p<<" ";
			p=p-1;//cout<<p<<" ";
			if(p<0)
			p=p+MOD;//cout<<p<<" ";
			p=(p*x)%MOD;//cout<<p<<" ";
			p=(p*d)%MOD;//cout<<p<<" ";
			s=((x-1)*(x-1))%MOD;//cout<<s<<" ";
			//qq=modular_exponentiation(s,SS,MOD);
			t=modular_exponentiation(s,SS-1,MOD);//cout<<t<<" ";
			v2=(p*t)%MOD;//cout<<v2<<" ";
		
			v=(v1+v2)%MOD;
			sum=(u+v)%MOD;
		
			printf("%lld\n",sum);
		}

	}
	return 0;
}
