#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,l,i,k,flag,flag2,flag3,flag4,x,y;
	char a[102];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		cin>>a;
		l=strlen(a);
		x=0;
		if(l==1)
		{
			a[0]='0';
			cout<<a<<endl;
			x++;
		}
		if(x==0)
		{
		   y=0;
		if(a[0]==a[l-1])
		{
			if(a[0]=='?'&&l==2)
			{
				a[0]='0';
				a[1]='1';
				cout<<a<<endl;
			    y++;
			}
			else if(a[0]=='?'&&l>2)
			{
				a[0]='0';
				a[l-1]='1';
			}
			else if(a[0]!='?')
			{
				printf("NO\n");
				y++;
			}
		}
		if(y==0)
		{
		    
	
			flag=0;
			for(i=0;i<l-1;i++)
	        {
	        	if(a[i]==a[i+1]&&a[i]!='?')
	        	flag++;
	        }
	        if(flag>0)
	        printf("NO\n");
	        else
	        {
	        	flag2=0;
	        	if(a[0]=='?')
	        	{
	        		if(a[1]!='0'&&a[l-1]!='0'&&k>0)
	        		a[0]='0';
	        		else if(a[1]!='1'&&a[l-1]!='1'&&k>1)
	        		a[0]='1';
	        		else if(k>2)
	        		a[0]='2';
	        		else
	        		flag2++;
	        	}
	        	if(flag2>0)
	        	printf("NO\n");
	        	else
	        	{
	        	    flag3=0;
	        	    for(i=1;i<l-1;i++)
	             	{
	             		if(a[i]=='?')
	             		{
	             			if(a[i-1]!='0'&&a[i+1]!='0'&&k>0)
	        		        a[i]='0';
	        				else if(a[i-1]!='1'&&a[i+1]!='1'&&k>1)
	        				a[i]='1';
	        				else if(k>2)
	        				a[i]='2';
	        				else
	        				flag3++;
	             		}
	        		    
	        	    }
	        	    if(flag3>0)
	        	    printf("NO\n");
	        	    else
	        	    {
	        	    		flag4=0;
	        	            if(a[l-1]=='?')
	        	            {
	        						if(a[0]!='0'&&a[l-2]!='0'&&k>0)
	        						a[l-1]='0';
	        						else if(a[0]!='1'&&a[l-2]!='1'&&k>1)
	        						a[l-1]='1';
	        						else if(k>2)
	        						a[l-1]='2';
	        						else
	        						flag4++;
	        				}
	        				if(flag4>0)
	        				printf("NO\n");
	        				else
	        				cout<<a<<endl;
	        	    }
	            }
	        }
		}
	  }
	}
	return 0;
}
