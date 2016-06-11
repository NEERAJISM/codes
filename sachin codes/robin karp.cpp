#include<bits/stdc++.h>
using namespace std;
#define M 1000007
#define d 10

string pat,text;

int calc(int m)
{
	int h=1;
	for(int i=1;i<=m-1;i++)
	h=(h*10)%M;
	return h;
}

bool confirm_it(int m,int s)
{
	for(int i=0;i<m;i++)
	{
		if(pat[i]!=text[s+i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int i,j;
	cout<<"enter text and pattern in seperate lines\n";
	cin>>text;  
	cin>>pat;
	int n=text.size();   int m=pat.size();
	int h=calc(m);
	
	int p=0,t0=0;
	
	for(i=0;i<m;i++)
	{
		p=((d*p)+1+(pat[i]-'a'))%M;
		t0=((d*t0)+1+(text[i]-'a'))%M;
	}
	
	//cout<<p<<endl<<t0;
	int t[n-m+2];
	t[0]=t0;
	
	for(int s=0;s<=n-m;s++)
	{
		if(p==t[s])
		{
			bool check=confirm_it(m,s);
			if(check)
			printf("pattern found at shift=%d\n",s);
		}
		
		{
			int x=h*(1+text[s]-'a'); 
			int y=d*(t[s]-x);         
			int z=(y+(1+text[s+m]-'a'))%M;      
			t[s+1]=z;
			if(t[s+1]<0)
			t[s+1]+=M;
		}
	}
	return 0;
}
