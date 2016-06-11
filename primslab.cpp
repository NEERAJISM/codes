#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main()
{
	int n,b[10],i,j,k,k1,v,v1,v2,sum = 0;
	cout<<"enter the number of nodes in graph\n";
	cin>>n;

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
            cin>>a[i][j];


	b[0]=1;
	k=1;
	v=100;

	while(1)
	{
	    int v=1000000;
		for(i=0;i<k;i++)                               // for array b
		{
			for(j=1;j<=n;j++)			                //FOR ARRAY A
			{

                if(v>a[b[i]][j]&&a[j][0]==0)
                {
                    v=a[b[i]][j];
                    v1=j;
                }
			}
		}
		a[1][0]=1;
		a[v1][0]=1;
		b[k]=v1;
        k++;

        if(k==n)
            break;

	}

	cout<<"the minimum spanning tree is ";
	for(i=0;i<k;i++)
	cout<<b[i]<<" ";
return 0;

}
