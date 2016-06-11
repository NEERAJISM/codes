#include<stdio.h>
 #include<iostream>
 using namespace std;
#include<stdio.h>
 
// A utility function that returns maximum of two integers
long long int max(long long int a, long long int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
long long int knapSack(long long int W, long long int wt[], long long int val[], int n)
{
   // Base Case
   if (n == 0 || W == 0)
       return 0;
 
   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
 
   // Return the maximum of two cases: (1) nth item included (2) not included
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}
int main()
{
	int t,n,i;
	long long int c,a[22],val[22],x,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&c);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		val[i]=a[i];
		x=knapSack(c,a,val,n);
		ans=c-x;
		printf("%lld\n",ans);
	}
	return 0;
}
