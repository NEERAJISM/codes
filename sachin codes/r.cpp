#include<iostream>
#include<stdio.h>
using namespace std;
char c[100000],d[100000];
int a[100000],b[100000];

void radix(int m)
{
	int k, i, j, temp, t, min=0;
	char e;
	for (k = 0; k < 6; k++)
    {    
        for (i = 0; i < m; i++)
        {
            min = b[i] % 10;        /* To find minimum lsd */
            t = i;
            for (j = i + 1; j < m; j++)    
            {
                if (min > (b[j] % 10))
                {
                    min = b[j] % 10; 
                    t = j;
                }
            }
            temp = a[t];e=c[t];
            a[t] = a[i];c[t]=c[i];
            a[i] = temp;c[i]=e;
            temp = b[t];
            b[t] = b[i];
            b[i] = temp;
 
        }
        for (j = 0; j < m; j++)        /*to find MSB */
            b[j] = b[j] / 10;
    }
}

int main()
{
	int t,n,m,i;
	scanf("%d",&t);
	while(t--)
	{
		long long int sum=1;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			cin>>c[i]>>a[i];
			b[i]=a[i];
		}
	
	    if(m==1)
		printf("1\n");
		else
		{
		    radix(m);                                                                                                 
		    for(i=0;i<m-1;i++)
		    {   
			    if(int(c[i]-c[i+1])!=0)
			    sum*=(a[i+1]-a[i]);
			    sum=sum%1000000009;
		    }
            
            sum=sum%1000000009;
		    printf("%lld\n",sum);
	    }
	}
	return 0;
}
