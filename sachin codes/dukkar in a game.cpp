#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,max,a[102],i,j,n;
	scanf("%d",&t);
	string s[102];
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			cin>>s[i]>>a[i];
			for(j=i-1;j>=0;j--)
			{
				if(s[j]==s[i])
				a[j]+=a[i];
			}
		}
		max=a[0];string c=s[0];
		for(i=0;i<n;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
				c=s[i];
			}
			else if(a[i]==max)
			{
				if(s[i]<c)
				{
						max=a[i];
						c=s[i];
				}
			}
		}
		cout<<c<<" "<<max<<endl;
	}
	return 0;
}
