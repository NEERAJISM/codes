#include<bits/stdc++.h>
using namespace std;

int pi[200005];

void prefix_func(char s[])
{
	int n=strlen(s);
	pi[0]=0;
	for(int i=1;i<n;i++)
	{
		int j=pi[i-1];
		while(j>0&&s[i]!=s[j])
		{
			j=pi[j-1];
		}
		if(s[i]==s[j])
		j=j+1;
		
		pi[i]=j;
	}
}

int main()
{
	char s2[200005];
	int i,n,l,x;
	while(scanf("%s",s2)!=-1)
	{
		char s1[200005],s[200005];
		n=strlen(s2);
		for(i=n-1;i>=0;i--)
		s1[n-1-i]=s2[i];//cout<<"hi";
		
		for(i=0;i<n;i++)
		s[i]=s1[i];
		s[n]='*';
		for(i=0;i<n;i++)
		s[n+i+1]=s2[i];
		//cout<<"hi";
		prefix_func(s); //cout<<"hello";
	
		//cout<<s<<endl;
		
		x=pi[n+n];
		int k=0;
		for(i=x;i<n;i++)
		{
			s2[n+k]=s1[i];
			k++;
		}
		for(i=0;i<n+k;i++)
		cout<<s2[i];
		
		cout<<endl;
	}
	return 0;
}
