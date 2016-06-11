#include<iostream>
using namespace std;
int main ()
{
	int n,i,j,t,h;
	
	cin>>t;
	for(j=1;j<=t;j++)
	{
		
		cin>>n;
		int c=n/2;
		if(n%2==0)
		{
		    h=1;
	    	for(i=1;i<=c;i++)
	    	{
	    		h=h*2;
	    		h+=1;
	    	}
     	}
     	else
     	{ h=1;
     	
     	  	for(i=1;i<=c;i++)
	    	{
	    		h=h*2;
	    		h+=1;
	    	}
	    	h=h*2;
        }
        cout<<h<<endl;
	
	}
	return 0;
	
}
