#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n1,n2,n3,num,i,x,c;
	map<int,int> m;
	map<int,int> ::iterator it;
	scanf("%d%d%d",&n1,&n2,&n3);
	for(i=0;i<(n1+n2+n3);i++)
	{
		cin>>x;
		m[x]+=1;
	}
	c=0;
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second>=2)
		c++;
	}
	printf("%d\n",c);
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second>=2)
		printf("%d\n",it->first);
	}
	return 0;
}
