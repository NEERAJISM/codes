#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char c[100002];
    int x,min,max,l,r,A,B,c1,c2,count,i,j,k,t;
    cin>>c;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d%d%d%d%d",&x,&min,&max,&l,&r);
    	for(i=l;i<=r;i++)
    	{
    		A=i;c2=0;
    	    cout<<"hello"<<i<<endl;
    		
    			j=0;c1=0;count=0;
    			while(i+j<=r&&j<max)
    			{
    				
    				int h[30]={0};
    				if(h[c[i+j]-'a']==0)
    				{
    					h[c[i+j]-'a']++;
    					count++;
    				}
    				if(count==x)
    				{
    					B=i+j;
    					if(B-A>=min-1)
    					{
    						c1++;
    						break;
    					}
    					
    				
    				}
    				j++;
    			}
    	
    			
    		if(c1>0)
    		break;
    	}
    	printf("%d %d\n",A,B);
    }
    return 0;

}
