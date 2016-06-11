#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,l,n,i,a[102],b[1002];
	char c[1002];
	scanf("%d",&t);
	while(t--)
	{
		cin>>c;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		l=strlen(c);
		
		for(i=0;i<l;i++)
		{
			b[i]=c[i]-'0';
		}
		sort(b,b+l);
		
		for(i=l/2;i<l;i++)
		cout<<b[i];
		for(i=(l/2)-1;i>=0;i--)
		cout<<b[i];
		
		cout<<endl;
	}
	return 0;
}
