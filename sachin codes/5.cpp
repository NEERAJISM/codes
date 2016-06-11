#include<iostream>
#include<string.h>
using namespace std;

void assign(string s,int c[])
{
	int i,j;
	for(i=0;i<26;i++)
	{
		for(j=0;j<s.length();j++)
		{
			if(char('a'+i)==s.at(j))
			{
				c[i]++;
			}
		}
	}
}


int main()
{
	string s1,s2;
	int a[26],b[26],sum,i;
	
	
	for(i=0;i<26;i++)
	{
		a[i]=0;
	}
	for(i=0;i<26;i++)
	{
		b[i]=0;
	}
	
	

		sum=0;
		cin>>s1>>s2;
		assign(s1,a);
		assign(s2,b);
	
	
	for(i=0;i<26;i++)
	{
		if(a[i]>b[i])
		sum+=(a[i]-b[i]);
		else
		sum+=(b[i]-a[i]);
	}
	cout<<sum<<"\n";

return 0;
	
}
