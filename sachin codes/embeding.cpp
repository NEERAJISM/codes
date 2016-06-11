#include<bits/stdc++.h>
using namespace std;
 
vector<pair<int,pair<int ,pair<int ,int> > > >  points;
vector<pair<int,int> > ans;

double d(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
 int t,n,A,B,S,p,q,X,Y,k,i,j,l,r;
 scanf("%d",&t);
 while(t--)
 {
     scanf("%d",&n);
     ans.resize(n+15);
     scanf("%d%d%d",&A,&B,&S);
     for(i=1;i<=n-1;i++)
     {
         scanf("%d%d%d%d",&X,&Y,&l,&r);
         points.push_back((make_pair(X,make_pair(Y,make_pair(l,r))))); 
        }
        
     sort(points.begin(),points.end());
     cout<<"points are\n";
     for(i=0;i<n-1;i++)
     cout<<points[i].first<<"   "<<points[i].second.first<<"  "<<points[i].second.second.first<<"  "<<points[i].second.second.second<<endl;
     
     
     k=0;
     ans[points[k].first].first=1;        ans[points[k].first].second=1;
     
     for(i=1;i<=400;i++)
     {
        for(j=2;j<=4000;j++)
        {
           if(d(ans[points[k].first].first , ans[points[k].first].second,i,j)>=points[k].second.second.first&&d(ans[points[k].first].first , ans[points[k].first].second,i,j)<=points[k].second.second.second)
           {
               //cout<<" i="<<i<<"j="<<j<< " "<<k<<endl;
               ans[points[k].second.first].first=i;      ans[points[k].second.first].second=j;
                k++; //cout<<k;
              }
              if(k==n-1)
              break;
           }
           if(k==n-1)
           break;
     }
    // cout<<"ans is\n";
     
     //printf("1 1\n");
     for(i=1;i<=n;i++)
     {
         printf("%d %d\n",ans[i].first,ans[i].second);
     }
     
    }
    return 0;
}
