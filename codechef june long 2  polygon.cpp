#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t,n,i,m[100000],j,high[100000],d,sorty[100000],county[100000],find1;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		for(i=0 ; i<n ; i++)
		{
		    //cout<<"**\n";
			scanf("%d",&m[i]);
			high[i] = -1000000000;

			for (j = 0; j < 2*m[i] ; j++)
			{
			    //cout<<"##\n";
				scanf("%d",&d);
				if(j%2==0 && d > high[i])
					high[i] = d;
			}
			sorty[i] = high[i];
		}

		sort(sorty,sorty+n);

		for(i=0 ; i<n ; i++)
		{
			find1 = sorty[i];
			for(j=0 ;j<n ;j++)
			{
				if(high[j] == sorty[i])
				{
				    county[j] = i;
                    break;
                }
			}
		}

		for (i = 0; i < n; ++i)
			printf("%d ",county[i]);

		printf("\n");
	}
return 0;
}
