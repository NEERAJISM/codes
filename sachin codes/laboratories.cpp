#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	string s;
	map<string, int> m;
	map<string, int> :: iterator it;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		m[s]++;
	}
	for(it = (m).begin(); it != (m).end(); it++)
	{
		
		cout<<it->first<<" "<<it->second<<endl;

	}
	return 0;
}
