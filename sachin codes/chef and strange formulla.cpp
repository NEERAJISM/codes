#include<bits/stdc++.h>
using namespace std;
long long int fac[10000003];

int main()
{
	fac[0] = 1;
	long long int n,m,i,x,y,z,s,a[100002],max,d;
	scanf("%lld%lld",&n,&m);
	for(i = 1 ; i<10000003 ; i++)
	{
		fac[i] = (i*fac[i-1]) % m;
	}
	
	//for(i=1;i<m;i++)
	//cout<<fac[i]<<"  ";
	
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	s=0;
	for(i=0;i<n;i++)
	{
		if(a[i]<=m-2)
		{
			x=(fac[a[i]+1])-1;
			if(x<0)
			x=m+x;
		}
		else
		x=m-1;//cout<<"x="<<x;
		
		if(a[i]%2==0)
		{
			d=a[i]/2;
		     y=(((((d%m)*(a[i]%m))%m)*((a[i]+1)%m)%m)%m);
		   
		}
		else
		{
			d=(a[i]+1)/2;
		     y=(((((d%m)*(a[i]%m))%m)*((a[i])%m)%m)%m);
		}
	
		//cout<<"y="<<y;
		z=(x+y)%m;//cout<<"z="<<z;
		s=(s+z)%m;//cout<<"s="<<s<<endl;
	}
	printf("%lld\n",s);
	return 0;
}
