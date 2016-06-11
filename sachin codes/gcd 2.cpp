#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int process(int a[],int l,int n)
{
	int i,p,r;
	p=a[0];
	for(i=0;i<(l-1);i++)
	{
		r=p%n; //cout<<"r="<<r;
		p=(r*10)+a[i+1];//cout<<"p="<<p;
	}
	return p;
}

int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int t,l,n,i,count,y,a[253],x;
	char c[253];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cin>>c;
		l=strlen(c);
		count=0;
		for(i=0;i<l;i++)
		{
			if(c[i]=='0')
			count++;
		}
		if(n==0)
		cout<<c<<endl;
		else if(count==l)
		printf("%d\n",n);
		else
		{
			
			for(i=0;i<l;i++)
			a[i]=c[i]-'0';
			x=process(a,l,n);
			//cout<<"x="<<x<<endl;
			y=gcd(x,n);
			printf("%d\n",y);
		}
		
	}
	return 0;
}
