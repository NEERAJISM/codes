#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,c1,c2,c,n;
	char s[100002],s1[100002],s2[100002];
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		n=strlen(s);
		c1=0;c2=0;
		
		for(i=0;i<n;i++)
		{
			if(i%2==0)
			{
				s1[i]='+';
				s2[i]='-';
			}
			else
			{
				s1[i]='-';
				s2[i]='+';
			}
		}
		for(i=0;i<n;i++)
		{
			if(s[i]!=s1[i])
			c1++;
			if(s[i]!=s2[i])
			c2++;
		}
		c=min(c1,c2);
		printf("%d\n",c);
	}
	return 0;
}
