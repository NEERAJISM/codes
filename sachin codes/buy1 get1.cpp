#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int main()
{
	int t,i,b,s;
	char c[201];
	cin>>t;
	while(t--)
	{
		int a[52]={0};
		cin>>c;
		
		s=0;
		for(i=0;i<strlen(c);i++)
	    {
	    	b=islower(c[i])?int(c[i]-'a'):26+int(c[i]-'A');
	    	(a[b])++;
	    }
	    for(i=0;i<52;i++)
	    {
	    	if(a[i]%2==0)
	    	a[i]=a[i]/2;
	    	else
	    	a[i]=(a[i]/2)+1;
	    }
	    for(i=0;i<52;i++)
	    s+=a[i];
	    
	    cout<<s<<endl;
	}
	return 0;
}
