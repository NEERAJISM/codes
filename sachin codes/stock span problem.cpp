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
	
	a[0]=12345;   // to avoid the stack from being empty;
	s.push(0);    // to avoid the stack from being empty;
	
	for(i=1;i<=n;i++)
	{
		while(a[s.top()]<=a[i])
		{
			s.pop();
		}
		cout<<"i="<<i<<"value="<<i-s.top()<<endl;
		s.push(i);
	}
	return 0;
}
