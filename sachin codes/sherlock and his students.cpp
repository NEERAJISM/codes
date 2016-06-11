#include<bits/stdc++.h>
using namespace std;
int n,q,i,flag,j,l,r,len;
long long int a[100002],s1,s2;
int main()
{
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		len=r-l+1;
		if(l==r)
		printf("%d\n",n-1);
		else if(len-1>(n/2))
		printf("0\n");
		else
		{
			
		
		int count=0;
		for(i=0;i<l-len;i++)
		{
			flag=0;
			for(j=i;j<i+len;j++)
			{
				s1=a[j]+a[l-i+j-1];
				s2=a[i]+a[l-1];
				if(s1!=s2)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			count++;
		}
		for(i=r;i<=n-len;i++)
		{
			flag=0;
			for(j=i;j<i+len;j++)
			{
				s1=a[j]+a[l-i+j-1];
				s2=a[i]+a[l-1];
				if(s1!=s2)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			count++;
		}
		printf("%d\n",count);
	 }
	
	}
	return 0;
}
