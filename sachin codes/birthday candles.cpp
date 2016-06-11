#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t,a[10],i,min,pos;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10;i++)
		{
			scanf("%d",&a[i]);
			
		}
		min=a[0];pos=0;
		for(i=1;i<10;i++)
		{
			if(a[i]<min)
			{
			   min=a[i];
			   pos=i;
		    }
	    }
	    if(pos!=0)
	    {
	    
	         for(i=1;i<=min+1;i++)
	         {
	         	printf("%d",pos);
	        	
	         }
	         printf("\n");
	    
		}
		else
		{
			for(int j=1;j<10;j++)
			{
				if(a[j]==min)
				{
					pos=j;
					break;
				}
			}
			if(pos==0)
			{
			    int x=pow(10,min+1);
			    printf("%d",x);
			    printf("\n");
			}
			else
			{
				    for(i=1;i<=min+1;i++)
	                {
	    	           printf("%d",pos);
	    	          
	                }
	                 printf("\n");
			}
			
		}
	}
	return 0;
}
