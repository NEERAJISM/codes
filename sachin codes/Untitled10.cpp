#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

long long int fact[100006];

void func()
{
	fact[0]=1;
	for(int i=1;i<100005;i++)
	fact[i]=(fact[i-1]*i)%M;
}

int main()
{
	int t,n,m,u,v,i,j;
	func();
	scanf("%d",&t);
	
	while(t--)
	{
		long long int x,y,sum,z;
		int storage[10][10];
		map<int,int> mp;
		map<int, int> :: iterator it;
		
		vector<pair<int,int> > g;
		
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			storage[i][j]=0;
		}
		
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			g.push_back(make_pair(u,v));
		}
	 
		if(m==0)
		printf("%lld\n",fact[n]);
		else
		{
		
			int maxi=pow(2,m);  //cout<<"m="<<maxi; 
			for(i=1;i<maxi;i++)
			{
				int count=0;  mp.clear();
				for(j=0;j<m;j++)
				{
					int z=pow(2,j);
					if(i&z)
					{
						count++;
						mp[g[j].first]++;   mp[g[j].second]++;
					}
				}
				bool flag=false; int co=0;
				for(it = (mp).begin(); it != (mp).end(); it++)
				{
					if(it->second==1)
					co++;
					if(it->second>2)
					flag=true;
				}
				
				int size=mp.size();
				
				
				if(flag==false&&co>0&&co%2==0)
				{
					storage[count][(2*count)-size]++;
				}
				
			}
			
			
			long long int ans=fact[n];   //cout<<"ans="<<ans;
			for(i=1;i<=m;i++)
			{
				sum=0;
				for(j=0;j<=i-1;j++)
				{
					x=pow(2,i-j);
					y=(storage[i][j]*x)%M;
					sum=(sum+y)%M;
				}
				z=(sum*fact[n-i])%M;  //cout<<"z="<<z<<endl;
				if(i%2==1)
				{
					ans=(ans-z);
					if(ans<0)  ans=ans+M;
				}
				else
				{
					ans=(ans+z)%M;
				}
			}
			
			printf("%lld\n",ans);
		}
	}
	return 0;
}
