#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
long long int fac[1000003];
char c[1000003];

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
	int t,k,x;
	long long int n,i,a[28],count,b[28],z,y,l;
	fac[0] = 1;
	for(i = 1 ; i<1000003 ; i++)
	{
		fac[i] = (i*fac[i-1]) % m;
	}
	scanf("%d",&t);
	while(t--)
	{
		cin>>c;
		l=strlen(c);
		for(i=0;i<28;i++)
		a[i]=0;
		for(i=0;i<l;i++)
		{
			x=int(c[i]-'a');
			a[x]++;
		}
		
		count=0;k=0;
		for(i=0;i<27;i++)
		{
			if(a[i]!=0)
			{//cout<<"a[i]="<<a[i];
				count+=a[i];
				y=modular_exponentiation(fac[a[i]],m-2,m);//cout<<"fac="<<fac[a[i]];
				b[k]=y;
				k++;
			}
		}//cout<<"count="<<count<<"k="<<k;
		z=fac[count];//cout<<"z="<<z<<endl;
		for(i=0;i<k;i++)
		{
			z=(z*(b[i]))%m;
		}
		printf("%lld\n",z);
	}
	return 0;
}
