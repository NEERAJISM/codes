#include<bits/stdc++.h>
using namespace std;
map<long long int, int> m;
//map<long long int, int> :: iterator it;
int main()
{
	int t,p,y,flag;
	long long int n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&flag);
		if(flag==1)
		{
			scanf("%lld%d",&n,&p);
			m[n]=p;
		}
		else
		{
			scanf("%lld",&x);
			//for(it = (m).begin(); it != (m).end(); it++)
			y=0;
			while(x!=0)
			{
				if(m.find(x)!=m.end())
				y=m.find(x)->second;
				x=x/2;
			}
			printf("%d\n",y);
		}
		
	}
	return 0;
}
