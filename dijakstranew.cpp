// check dijkstra vs flloyd warshalls

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n,i,j,a[100][100],dist[100],src,tsrc,n1,v[101],min1,t,m,k,r,source,destination;
string s2,s3;
int findmin()
{
	int min1 = 2147483647 ,mini;

	for(int j =1 ; j <= n ; j++)
	{
		if(dist[j] < min1 && v[j] == 0)
			mini = j, min1 = dist[j];
	}

	//cout<<min1<<" "<<mini<<endl;
	return mini;
}

void assignvalues(int tsrc)
{
	for(int i=1 ;i<=n; i++)
		if(v[i] == 0 && a[tsrc][i] != 2147483647 && dist[tsrc]!= 2147483647 && (a[tsrc][i] + dist[tsrc])< dist[i] )
            dist[i] = a[tsrc][i]+dist[tsrc];
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=n ; j++)
                a[i][j]= 2147483647;

        vector<string> v2(n);

        for(i=1 ; i<=n ; i++)
        {
            scanf("%s",&s2);

            v2.push_back(s2);

            scanf("%d",&m);

            for(j=1 ; j<=m ; j++)
            {
                scanf("%d",&k);
                scanf("%d",&a[i][k]);
            }
        }

        scanf("%d",&r);

        for(k=1 ; k<=r ; k++)
        {
            scanf("%s",&s2);
            scanf("%s",&s3);

            for(j=0 ;j<n ;j++)
            {
                v[j+1] = 0;

            	if(v2[j]==s2)
            		src = j+1;
            	else if(v2[j]==s3)
            		destination = j+1;
            }

           // cout<<"src "<<src<<"dest "<<destination<<endl;

            for(i=1 ; i<=n ; i++)
                dist[i] = 2147483647;

        	dist[src]  = 0;
            n1= n;
       		while(n1--)
        	{
            	v[src] = 1;
           	 	assignvalues(src);
            	src = findmin();
        	}

            printf("%d\n",dist[destination]);
        }
    }
    return 0;
}
