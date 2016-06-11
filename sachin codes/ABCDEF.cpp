#include<bits/stdc++.h>
using namespace std;

int lhs[1000003],rhs[1000003];

int main()
{
	int n,p,q,i,j,k,x,count,a[103],ans,c,co;
	scanf("%d",&n);

	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	p=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a[k]!=0)
				rhs[p++]=a[k]*(a[i]+a[j]);
			}
		}
	}
	q=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				//if(k!=0)
				lhs[q++]=a[k]+(a[i]*a[j]);
			}
		}
	}
	
	sort(lhs,lhs+q);
	sort(rhs,rhs+p);
	
	ans=0;j=0;
	for(i=0;i<q;)
	{
		x=lhs[i]; c=0;
		for(k=i;k<q;k++)
		{
			if(lhs[k]==x)
			c++;
			else
			break;
		}
		i=i+c;
		count=0;
		while(j<p)
		{
			
			if(x==rhs[j])
			count++;
			else if(x<rhs[j])
			{
				co=j;
				break;
			}
			j++;
		}
		j=co;
		ans=ans+(c*count);
	}
	printf("%d\n",ans);
	return 0;
	
}
