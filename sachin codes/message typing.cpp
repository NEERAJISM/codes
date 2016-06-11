#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,i,l;
	long long int s;
	char c[1004];
	scanf("%d",&t);
	while(t--)
	{
		cin>>c;
		l=strlen(c);
		s=0;
		for(i=0;i<l;i++)
		{
			s+=((c[i]-'a')+1);
		}
		printf("%lld\n",s);
	}
	return 0;
}
