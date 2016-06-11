#include<bits/stdc++.h>
using namespace std;
map<long long int, int> m1;
map<long long int, int> m2;
//map<long long int, int> :: iterator it;
int main()
{
	int t,p,y,flag,z,yf,T,zmax;
	long long int n,x;
	scanf("%d",&T);
	
	for(t=1;t<=T;t++)
	{
		scanf("%d",&flag);
		if(flag==1)
		{
			scanf("%lld%d",&n,&p);
			m1[n]=p;
			m2[n]=t;
		}
		else
		{
			scanf("%lld",&x);
			//for(it = (m).begin(); it != (m).end(); it++)
			yf=0;zmax=0;
			while(x!=0)
			{
				if(m1.find(x)!=m1.end())
				{
					y=m1.find(x)->second;
					z=m2.find(x)->second;
					if(z>zmax)
					{
						yf=y;
						zmax=z;
					}
				}
				x=x/2;
			}
			printf("%d\n",yf);
		}
		
	}
	return 0;
}
