#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char c[100012];
int main()
{
	int t,i,n,c1,c2;
	scanf("%d",&t);
	while(t--)
	{
		cin>>c;
		c1=0;c2=0;
		int l=strlen(c)-2;
		for(i=0;i<l;i++)
		{
			if(c[i]=='0'&&c[i+1]=='1'&&c[i+2]=='0')
			{
				c1++;
				break;
			}
			if(c[i]=='1'&&c[i+1]=='0'&&c[i+2]=='1')
			{
				c2++;break;
			}
		}
		if(c1==1||c2==1)
		printf("Good\n");
		else
		printf("Bad\n");
		
	}
	return 0;
}
