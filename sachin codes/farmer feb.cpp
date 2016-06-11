#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int c[500],k=0;
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
	int t,x,y,z,n,i,sum,flag;
	sieve(2005);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		sum=x+y;
		for(i=0;i<=k;i++)
		{
			if(c[i]>sum)
			{
				z=c[i];
				break;
			}
		}
		printf("%d\n",z-sum);
	}
	return 0;
}
