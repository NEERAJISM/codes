#include<iostream>
#include<stdio.h>
int main()
{
	int t,n,i,a,b;
	scanf("%d",&t);
	while(t--)
    {
    	scanf("%d",&n);
        a=n/7;
    	b=n%7;
    	i=0;
    	while(a-i!=-1)
    	{
    		
    		if((b+7*i)%4==0)
    		{
    		printf("%d\n",(a-i)*7);
    		break;}
    		i++;
    	}
		if(a-i==-1)
		printf("-1\n");    
    
    	
    }
    return 0;
}
