#include<bits/stdc++.h>
using namespace std;

int b[10002],primes[1300],k=0;

void sieve()
{
	for(int i=0;i<=10000;i++)
	b[i]=0;
	
	for(int i=2;i<=10000;i++)
	{
		if(b[i]==0)
		{
			primes[k++]=i;
			int j=2;
			while(i*j<=10000)
			{
				b[i*j]=1;
				j++;
			}
		}
	}
}

int main()
{
	int t,n,a[10003];
	bool flag;
	sieve();
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		int count=0;
		
		if(a[0]==1)
		{
			a[0]=2;
			count++;
		}
		
		for(int i=1;i<n;i++)
		{
			if(a[i]<a[i-1])
			{
				count+=(a[i-1]-a[i]);
				a[i]=a[i-1];
				
			}
		}
		
		//cout<<"count="<<count<<endl;
		//for(int i=0;i<n;i++)
		//cout<<a[i]<<"  ";
		
		
		
		int ans=0;
		for(int j=1;j<n;j++)
		{
			if(a[j]%a[0]!=0)
			ans+=(a[0]-(a[j]%a[0]));
		}
		
		for(int i=0;i<k;i++)
		{
			int sum=0;
			if(primes[i]<a[0])
			{
				for(int j=0;j<n;j++)
				{
					if(a[j]%primes[i]!=0)
					sum+=(primes[i]-(a[j]%primes[i]));
				}
				if(sum<ans)
				ans=sum;
			}
		}
		
		printf("%d\n",ans+count);
	}
	return 0;
}
