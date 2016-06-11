#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int maxSubArraySum(int a[], int size,int k)
{
   int max_so_far = k, max_ending_here = k;
   int i;
   for(i = 0; i < size; i++)
   {
     max_ending_here = max_ending_here ^ a[i];
     if(max_ending_here < max_so_far)
        max_ending_here = max_so_far ;
     if(max_so_far < max_ending_here)
        max_so_far = max_ending_here;
    }
    return max_so_far;
}
int main()
{
	int t,n,i,k,a[1003],max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		//sort(a,a+n);
	   	max=maxSubArraySum(a,n,k);
	   
		printf("%d\n",max);
	}
	return 0;
} 
