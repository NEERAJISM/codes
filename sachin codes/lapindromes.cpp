#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char c[1000];

int main()
{
	int t,i,j,d,x,y,l;
	scanf("%d",&t);
	while(t--)
	{
		int a[200]={0},b[200]={0};
		d=0;
		cin>>c;
		l=strlen(c);
		if(l%2==0)
		y=l/2;
		else
		y=(l/2)+1;
		for(i=0;i<(l/2);i++)
		{
			x=int(c[i]);
			a[x]++;
		}
		for(i=y;i<l;i++)
		{
			x=int(c[i]);
			b[x]++;
		}
		for(i=0;i<200;i++)
		{
			if(a[i]==b[i])
			d++;
		}
		if(d==200)
		printf("YES\n");
		else 
		printf("NO\n");
	}
     return 0;
}
