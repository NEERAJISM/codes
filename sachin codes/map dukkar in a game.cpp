#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,x,i,max;
	string s,smax;
	map<string, int> m;
	map<string, int> :: iterator it;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			cin>>s;
			scanf("%d",&x);
			m[s]+=x;//             it adds the value if s already exists otherwise creates a new key
			                  //    if you do not want to create new one and only check that whether
			                  //    it exists or not then use find not this otherwise it will create a new key
		}
		max=0;
		for(it = (m).begin(); it != (m).end(); it++)
		{
			if(it->second>max)
			{
				max=it->second;
				smax=it->first;
			}//cout<<it->first<<" "<<it->second<<endl;
		}
		cout<<smax<<" "<<max<<endl;
		m.clear();
	}
	return 0;
}
