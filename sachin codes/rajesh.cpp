#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;int ar[n];
		for(int i=0;i<n;i++)cin>>ar[i];
		
		stack<int>st;
		st.push(0);
		
		int next,ele;
		for(int i=1;i<n;i++)
		{
			if(!st.empty())
			{
				next=ar[i],ele=ar[st.top()];st.pop();
				
				while(!st.empty()&&ele<next)
				{
					cout<<ele<<" "<<next<<endl;
					ele=ar[st.top()];st.pop();
				}
			}
			st.push(i);
		}
		while(!st.empty()&&ele<next)
				{
					cout<<ele<<" "<<next<<endl;
					ele=st.top();st.pop();
				}
	}
}
