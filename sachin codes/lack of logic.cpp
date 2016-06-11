#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,i,d,l,x;
	char cr,ab;
	char s[350];
	scanf("%d",&t);
    while(t--)
	{
		scanf("%c",&ab);
		scanf("%[^\n]s",s);
		int a[130]={0};
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			x=int(s[i]);
			a[x]++;
		}
		int flag=0;
		for(i=0;i<130;i++)
		{
			if(i>=65&&i<=90)
		    {
		    	if(a[i]+a[i+32]==0)
		    	{
		    		flag++;
		    		d=i;
		    		break;
		    	}
		    }
		}
		
		
		if(flag!=0)
		{
			cr=char(d);
			cout<<cr<<endl;
		}
		if(flag==0)
		{
			if(a[32]==0)
			printf(" \n");
			else
			printf("~\n");
		}
		
	}
	return 0;
}
