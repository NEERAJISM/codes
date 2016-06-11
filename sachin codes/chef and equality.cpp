#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,a[100002];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		sort(a,a+n);
		 int max_so_far = 0;
		 int max_ending_here = 0;
		 int x=a[0];
		 
		for(i=0;i<n;i++)
		{
			if(a[i]==x)
			++max_ending_here;
			else
			{
				max_ending_here=1;
				x=a[i];
			}
			if(max_ending_here>max_so_far)
			max_so_far=max_ending_here;
		}
		printf("%d\n",n-max_so_far);
	}
	return 0;
}
