#include<bits/stdc++.h>
using namespace std;
char s[100003];
int n,type;

int func1()
{
	int i,a[100002],b[100002],k=0,K=0,ans=0;
	for(i=0;i<n;i++)
	{
		if(s[i]!='B'&&i%2==0)
		a[k++]=i;
		if(s[i]!='G'&&i%2!=0)
		b[K++]=i;
	}
	for(i=0;i<k;i++)
	{
		if(type==2)
		ans+=2*pow(abs(b[i]-a[i]),type-1)-1;
		else
		ans+=pow(abs(b[i]-a[i]),type);
	}
	return ans;
}
int func2()
{
	int i,a[100002],b[100002],k=0,K=0,ans=0;
	for(i=0;i<n;i++)
	{
		if(s[i]!='G'&&i%2==0)
		a[k++]=i;
		if(s[i]!='B'&&i%2!=0)
		b[K++]=i;
	}
	for(i=0;i<k;i++)
	{
		if(type==2)
		ans+=2*pow(abs(b[i]-a[i]),type-1)-1;
		else
		ans+=pow(abs(b[i]-a[i]),type);
	}
	return ans;
}

int main()
{
	int t,i,x,y,z,c1,c2,c3,c4;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&type);
		cin>>s;
		n=strlen(s);
		x=0;y=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='B')
			x++;
			else
			y++;
		}
		if(abs(x-y)>1)
		printf("-1\n");
		else
		{
			if(x>y)
			{
				int coun=func1();
				printf("%d\n",coun);
			}
			else if(x<y)
			{
				int co=func2();
				printf("%d\n",co);
			}
			else if(x==y)
			{
				int cou=min(func1(),func2());
				printf("%d\n",cou);
			}
		}
	}
	return 0;
}
