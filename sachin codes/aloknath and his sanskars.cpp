#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,i,j,n,k,b,flag1,flag2;
	long long int a[23],s,r,x,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		if(k>n)
		{
		  	r=0;
			for(i=0;i<n;i++)
			r+=a[i];
			if(r==0)
			printf("yes\n");
			else
			printf("no\n");
		}
		else
		{
			s=0;
			for(i=0;i<n;i++)
			s+=a[i];
			                                  //cout<<"sum"<<s<<endl;
			b=s%k;                           //cout<<"b="<<b<<endl;
			if(b!=0)
			printf("no\n");
			else
			{                                //cout<<"hi"<<k<<endl;
				c=s/k;              //cout<<"c="<<c<<endl;
				sort(a,a+n);
				flag1=0;
				for(i=0;i<k;i++)
				{
					x=0;
					for(j=n-1;j>=0;j--)
					{
						
						if(x+a[j]<=c)
						{
							x+=a[j];
							a[j]=0;
						}
					}                 //cout<<"x="<<x<<endl;
					if(x!=c)
					{
						flag1=1;
					                     	
						break;
					}
					
				}
				flag2=0;
				for(i=0;i<k;i++)
				{
					x=0;
					for(j=0;j<n;j++)
					{
						
						if(x+a[j]<=c)
						{
							x+=a[j];
							a[j]=0;
						}
					}                 //cout<<"x="<<x<<endl;
					if(x!=c)
					{
						flag2=1;
					                     	
						break;
					}
					
				}
				if(flag1==1&&flag2==1)
				printf("no\n");
				else
				printf("yes\n");
			}
		}
		
	}
	return 0;
}
