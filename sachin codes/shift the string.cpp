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
	int i,n,l,pos,max;
		cin>>n;
		cin>>s1;
		cin>>s2;
		string s=s1+'*'+s2+s2;
		
		l=s.length();
		
		prefix_func(s);
	
		//cout<<s<<endl;
		max=0;
		for(i=n;i<l;i++)
		{
			if(pi[i]>max)
			{
				max=pi[i];
				pos=i;
			}
		}
		cout<<pos-n-max<<endl;
	
	return 0;
}
