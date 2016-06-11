#include<bits/stdc++.h>
using namespace std;

int A[10007],primes[10000],k=0;

void SieveOfEratosthenes(int n)
{
	int i,j;
	A[1]=3;
	for(i=2;i<=n;i++)
	{
		if(A[i]==0)
	 	{
	 		primes[k++]=i;
	 		j=2;
	 		while((i*j)<=n)
	 		{
	 			A[i*j]=1;
	 			j++;
	 		}
	 	}
	}
}


int main()
{
	SieveOfEratosthenes(10005);
	int t,n,l,i,x,max;
	char s[10002];
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		l=strlen(s);
		int a[61];
		for(i=0;i<61;i++)
		a[i]=0;
		for(i=0;i<l;i++)
		{
			x=int(s[i]-'A');
			a[x]++;
		}
		max=0;
		for(i=0;i<61;i++)
		{
			if(a[i]>max)
			max=a[i];
		}//cout<<"max"<<max<<endl;
		if(max==1)
		{
			printf("%d\n",l);
		}
		else
		{
		 	if(A[max]==0)   //is prime
			{
				for(i=0;i<61;i++)
				{
					if(A[a[i]]==0)
					a[i]=(a[i]-(a[i]/2));
				}
			}
			else if(A[max]==1)
			{
				for(i=0;i<61;i++)
				{
					if(A[a[i]]==1)
					a[i]=(a[i]-(a[i]/2));
				}
			}
			int ans=0;
			for(i=0;i<61;i++)
			{
				ans+=a[i];
				//cout<<a[i]<<"  ";
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
