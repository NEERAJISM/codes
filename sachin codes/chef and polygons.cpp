#include<bits/stdc++.h>
using namespace std;
#define INF 1000000001

vector<pair<long long int ,int > >arr;

int main()
{
    int t,n,m,p,q,i,j;
	long long int x,y,min_x,min_y,max_x,max_y;
    scanf("%d",&t);
    while(t--)
    {
		
    	scanf("%d",&n);
    	arr.clear();
    	arr.resize(n+2);
    	int ans[n+2];
    	
    	for(i=1;i<=n;i++)
    	{
    		scanf("%d",&m);
    		min_x=min_y=INF;  max_x=max_y=-INF;
    		
    		for(j=1;j<=m;j++)
    		{
    			scanf("%lld%lld",&x,&y);
    			if(x<min_x)
    			{
    				min_x=x;
    				//min_x2=y;
    			}
    			if(y<min_y)
    			{
    				min_y=y;
    				//min_y2=x;
    			}
    			if(x>max_x)
    			{
    				max_x=x;
    				//max_x2=y;
    			}
    			if(y>max_y)
    			{
    				max_y=y;
    				//max_y2=x;
    			}
    		}
    		long long int d=(max_x-min_x)*(max_y-min_y);
    		arr[i].first=d;
    		arr[i].second=i;
    	}
    	
    	sort(arr.begin()+1,arr.begin()+n+1);
    	
    	for(i=1;i<=n;i++)
    	{
    		ans[arr[i].second]=i-1;
    	}
    	for(i=1;i<=n;i++)
    	cout<<ans[i]<<" ";
    	
    	cout<<endl;
    }
    return 0;
}
