#include<bits/stdc++.h>
using namespace std;

int pi[50000002];

void prefix_func(string s)
{
	int n=(int)s.length();
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
	string s1,s2;
	int i,n,l;
	while(scanf("%d",&n)!=EOF)
	{
		cin>>s1;
		cin>>s2;
		string s=s1+'*'+s2;
		
		l=s2.length();
		
		prefix_func(s);
	
		//cout<<s<<endl;
		
		for(i=n;i<l+n+1;i++)
		{
			if(pi[i]==n)
			cout<<i-n-n<<endl;
		}
		cout<<endl;
	}
	return 0;
}
