#include<iostream>
#include<stdio.h>
using namespace std;

int funx(long long int a[],int n,int k,long long int ans)
{
	int i,j;
	long long int h;
	h=ans;
		for(j=0;j<n;j++)
		{
			h=h^a[j];
		}
	if(k%2==0)
	printf("%lld\n",ans);
	else
	printf("%lld\n",h);
}

int funo(long long int a[],int n,int k,long long int ans)
{
	int i,j;
		for(j=0;j<n;j++)
		{
			ans=ans|a[j];
		}
	if(k==0)
	ans=0;
	printf("%lld\n",ans);
}

int funa(long long int a[],int n,int k,long long int ans)
{
	int i,j;
		for(j=0;j<n;j++)
		{
			ans=ans&a[j];
		}
	if(k==0)
	ans=0;
	printf("%lld\n",ans);
}

int main()
{
	int t,n,k,i,j;
	long long int a[1002],ans;
	char c[5];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%lld",&n,&k,&ans);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		cin>>c;
		if(c[0]=='X')
		funx(a,n,k,ans);
		else if(c[0]=='O')
		funo(a,n,k,ans);
		else
		funa(a,n,k,ans);
	}
	return 0;
}
