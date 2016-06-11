#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
 
vector<int> parent;
//int s[maxn];
vector<int> s;
 
/*void make_set(int v) 
{
 parent[v]=v;
 //rank[v]=0;
}*/
 
int find_set(int v)
 {
 if(v==parent[v])
  return v;
 return parent[v] = find_set (parent[v]);
}
 
void union_set(int root_a,int root_b) 
{
 	
		if(s[root_a]<s[root_b])
		parent[root_a]=root_b;
		else if(s[root_a]>s[root_b])
		parent[root_b]=root_a;
		
		//if(rank[root_a]==rank[root_b])
		//++rank[root_a];
    
}
 
 
int main()
{
 int u,v,w,i,n,m,t,ans,Z;
 scanf("%d",&t);
 while(t--)
 {
 
 parent.clear();
 s.clear();	
 
 scanf("%d",&n);
 
  parent.resize(n+2);
 s.resize(n+2);
 
 for(i=1;i<=n;i++)
 {
 	scanf("%d",&s[i]);
 	parent[i]=i;
 }
 scanf("%d",&m);
 
 
 
 
 
 while(m--)
 	{
  		scanf("%d",&Z);
  		if(Z==0)
  		{
    			scanf("%d%d",&u,&v);
    			 int y=find_set(u);
 				 int z=find_set(v);
 				if(y!=z)
  				{
   						union_set(y,z);
  				}
  				else
  				printf("Invalid query!\n");
  				
  		}
 		 else
  		{
  			scanf("%d",&u);
  			ans=find_set(u);
  			printf("%d\n",ans);
  		}
 	}
 
 printf("\n");
 
}
 
 return 0;
} 
