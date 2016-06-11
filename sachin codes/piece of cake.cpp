#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,i,l,max,s,index,a[27],x;
	char c[53];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<27;i++)
		a[i]=0;
		
		cin>>c;
		l=strlen(c);
		for(i=0;i<l;i++)
		{
			x=int(c[i]-'a');
			a[x]++;
		}
		
		max=0;
		for(i=0;i<27;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
				index=i;
			}
		}
		
		s=0;
		for(i=0;i<27;i++)
		{
			if(i!=index)
			s+=a[i];
		}
		
		if(s==max)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
