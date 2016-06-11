#include<bits/stdc++.h>
using namespace std;

int a[100002],b[100002],hash[100002],d[100002];

int main()
{
	int t,n,k,m,i,j,diff,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&m);
		
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		
		for(i=0;i<=100001;i++)
		{
			hash[i]=0;
		}
		
		for(i=1;i<=k;i++)
		{
			scanf("%d",&x);  hash[x]++;
		}
		
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);   hash[x]++;
		}
		
		for(i=0;i<n;i++)
		d[i]=a[i]-b[i];
		
		sort(d,d+n);
		
		for(i=0;i<n;i++)
		{
			diff=d[i];              //cout<<"i="<<i;
			for(j=diff;j>=1;j--)
			{
				if(hash[j]>=1)
				{
					hash[j]--;   d[i]=d[i]-j;  //cout<<"diff="<<diff<<"white="<<j<<endl;
					break;
				}
			}
		}
		
		long long int ans=0;
		for(i=0;i<n;i++)
		{
			ans=ans+d[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
