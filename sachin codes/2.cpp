#include<iostream>
using namespace std;
int main()
{
	int n,i,j,c=0,d,b[26];
	char s[109];
		for(i=0;i<26;i++)
	{
		b[i]=0;
	};
	cin>>n;

	for(i=1;i<=n;i++)
	{
		
		cin>>s;
		
		for(j=0;s[j] != '\0';j++)
		{
			//cout<< s[j];
				d=int(s[j]-'a');
			if(b[d]==i-1)
			{
				b[d]=i;
			};
			
		
		};
	
	};
	for(i=0;i<26;i++)
	{
		if(b[i]==n)
		c++;
	};
	cout<<c;
	return 0;
	
}
