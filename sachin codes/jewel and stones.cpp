#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char c[102],d[102];

int main()
{
	int t,i,j,x,y,l;
	scanf("%d",&t);
	while(t--)
	{
		int a[202]={0},b[202]={0};
		y=0;
		cin>>c>>d;
		for(i=0;i<strlen(c);i++)
		{
			x=int(c[i]);
			a[x]++;
		}
		for(i=0;i<strlen(d);i++)
		{
			x=int(d[i]);
			b[x]++;
		}
		for(i=0;i<202;i++)
		{
			if(a[i]!=0&&b[i]!=0)
			y+=b[i];
		}
		printf("%d\n",y);
	}
     return 0;
}
