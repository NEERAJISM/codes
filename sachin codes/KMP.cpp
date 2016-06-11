#include<bits/stdc++.h>
using namespace std;

int pi[50];

void prefix_fn(string st)
{
	int i,x,j;
	int n=st.size();
	pi[0]=0;
	for(i=1;i<n;i++)
	{
		j=pi[i-1];
		while(j>0&&st[i]!=st[j])
		{
			j=pi[j-1];
		}
		if(st[i]==st[j])
		j++;
		
		pi[i]=j;
	}
}

int main()
{
	string s,t;
	cout<<"enter pattern and text\n";
	cin>>s;
	cin>>t;
	
	string st;
	st=s+'*'+t;
	
	prefix_fn(st);
	
	int m=s.size();  // size of pattern;
	int n=st.size();  // size of pattern + 1 + size of text;
	for(int i=0;i<n;i++)
	{
		if(pi[i]==m)
		{
			cout<<"pattern matched at shift ="<<(i-m-m)<<endl;
		}
	}
	
	return 0;
}
