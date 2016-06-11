#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int t,n,i,k,a[101];
	scanf("%d",&t);
	while(t--)
	{
		int s1=0,s2=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		if(n==1)
		printf("0\n");
		else if(k<=(n/2))
		{
		    for(i=0;i<k;i++)
		    s1+=a[i];
		    for(i=k;i<n;i++)
		    s2+=a[i];
		    printf("%d\n",abs(s2-s1));
		}
		else
		{
		    for(i=0;i<n-k;i++)
		    s1+=a[i];
		    for(i=n-k;i<n;i++)
		    s2+=a[i];
		    printf("%d\n",abs(s2-s1));
		}
	}
	return 0;
}
