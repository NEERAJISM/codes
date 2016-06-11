#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	
	stack<int> st;
	st.push(s[0]-'0');
	st.push(s[1]-'0');
	
	for(int i=2;i<n;i++)
	{
		if(isdigit(s[i]))
		st.push(s[i]-'0');
		else
		{
			int x=st.top();  st.pop();
			int y=st.top();  st.pop();
			
			if(s[i]=='+')
			st.push(y+x);
			else if(s[i]=='-')
			st.push(y-x);
			else if(s[i]=='*')
			st.push(y*x);
			else if(s[i]=='/')
			st.push(y/x);
			else if(s[i]=='%')
			st.push(y%x);
		}
	}
	cout<<"res="<<st.top();
	return 0;
}
