#include<iostream>
#include<stdio.h>
#define mod 1000000009
using namespace std;
int a[100002];
int main()
{
	int t,n,m,i,j,k,x;
	char c;
	scanf("%d",&t);
	while(t--)
	{
		
		long long int sum=1;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			cin>>c>>x;
			a[x]=int(c);
		}
		    for(k=0;k<100002;k++)
			{
				if(a[k]!=0)
				{
					i=k;
					break;
				}
			}                                                                                           
		    while(i<100001)
		    { 
			    j=1;  
			    while(a[i+j]==0&&i+j<100001)
			    {
			    	j++;
			    }
			    if((a[i+j]-a[i])!=0)
			    {
			        sum=sum*j;
			        
			        sum=sum%mod;
				}
			    
			    i=i+j;
		    }
            
            sum=sum%mod;
		    cout<<sum<<endl;
	    
	}
	return 0;
}
