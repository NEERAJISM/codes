#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int b[100002],c[100],k=0;
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1;
        ++i;
    }
}
void sieve(int n)
{
  
    if (n >= 2)
    {
       
        bool arr[n];
        memset(arr, 0, sizeof(arr));
 
        
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                
                c[k]=i+1;
                k++;
                markMultiples(arr, i+1, n);
            }
        }
    }
}
int main()
{
	int t,i,n,max,j,ans,count,min;
	sieve(332);
	for(i=0;i<k;i++)
cout<<c[i]<<"  ";
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		
		ans=-1;
		for(i=0;i<k;i++)
		{
			count=0;
			for(j=0;j<n;j++)
			{
				if(b[j]%c[i]==0)
				{
					count++;
				}
			}
			if(count==n)
			{
				ans=c[i];
				break;
			}
		}
		min=b[0];
		for(i=0;i<n;i++)
		{
			if(b[i]<min)
			min=b[i];
		}
		int flag=0;
			for(i=0;i<n;i++)
			{
				if(b[i]%min==0)
				flag++;
			}
		
		if(flag==n&&ans==-1&&min!=1)
		ans=min;
		
		printf("%d\n",ans);
	}
	return 0;
}
