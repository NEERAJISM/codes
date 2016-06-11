#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char m[25002],w[25002];
int main()
{
	int t,i,d,j,l1,l2;
	scanf("%d",&t);
	while(t--)
	{
		cin>>m>>w;
		l1=strlen(m);
		l2=strlen(w);
		if(l1>l2)
		{
			i=0;j=0;d=0;
			while(i<l1&&j<l2)
			{
				if(w[j]==m[i])
				{
					j++;i++;d++;
				}
				else
				{
					i++;
				}
			}
			if(d==l2)
			printf("YES\n");
			else
			printf("NO\n");
		}
		else if(l1<l2)
		{
			i=0;j=0;d=0;
			while(i<l1&&j<l2)
			{
				if(w[j]==m[i])
				{
					j++;i++;d++;
				}
				else
				{
					j++;
				}
			}
			if(d==l1)
			printf("YES\n");
			else
			printf("NO\n");
		}
		else if(l1==l2)
		{
			d=0;
			for(i=0;i<l1;i++)
			{
				if(w[i]==m[i])
				d++;
			}
			if(d==l1)
			printf("YES\n");
			else
			printf("NO\n");
		}
	}
	return 0;
}
