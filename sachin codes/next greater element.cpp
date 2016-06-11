#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
	int n,i,x;
	stack<int> s;
	
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	
	a[0]=12345;   // to avoid the stack from being empty;  some max value
	s.push(a[0]);    // to avoid the stack from being empty;
	
	for(i=1;i<=n;i++)
	{
		int next=a[i];
		while(s.top()<next)
		{
			cout<<s.top()<<"  "<<next<<endl;
			s.pop();
		}
		s.push(next);
	}
	while(s.top()!=12345)
	{
		cout<<s.top()<<"   -1"<<endl;
		s.pop();
	}
	return 0;
}
