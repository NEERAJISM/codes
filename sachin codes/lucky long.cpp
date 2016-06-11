#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char c[100002];
int a[100002];
int main()
{
	int t,i,count,l;
	scanf("%d",&t);
	while(t--)
	{
		cin>>c;
		l=strlen(c);
		count=0;
		for(i=0;i<l;i++)
		{
			a[i]=int(c[i]-'0');
			if(a[i]!=4&&a[i]!=7)
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
