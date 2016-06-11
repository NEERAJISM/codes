#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,g,n,r,d,i,q,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&g);
		while(g--)
		{
			scanf("%d%d%d",&i,&n,&q);
		    r=(n+i)%2;
		    d=n%2;
		    q=q%2;
		    if(d==0)
		    c=n/2;
		    else {
		    	
		    if(q==r)
		    c=(n/2)+1;
		    else
		    c=n/2;
		}
		    
			printf("%d\n",c);
		}
	}
	return 0;
	
}
