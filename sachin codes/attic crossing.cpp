#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char c[1000002];
int main()
{
	int t,i,max,j,count,d,n,pos;
	scanf("%d",&t);
	while(t--)
	{
		cin>>c;
		n=strlen(c);
		d=0;
		for(i=0;i<n;i++)
		{
			if(c[i]=='.')
			{
				d++;
				pos=i;
				break;
			}
		}
		if(d==0)
		printf("0\n");
		else
		{
		
		i=0;max=1;
		count=0;
		while(i<n)
		{
			j=1;
			if(c[i]=='.')
			{
			
				while(c[i+j]=='.'&&(i+j)<n)
				{
					j++;
				}
				if(j==1&&i==pos)
				count++;
			}
			if(j>max)
			{
				max=j;
				count++;
			}
			i+=j;
		}
		printf("%d\n",count);
	   }
	}
	return 0;
}
