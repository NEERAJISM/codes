#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,arr[10],cop[10],flag,i,j,k,min,index;
	long long int x;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
		for(i=0;i<10;i++)
		cop[i]=arr[i];
		flag=false;
		if(arr[0]<arr[1])
		{
			for(i=1;i<=10;i++)
			{
				x=0;
				if(arr[0]<i)
				{
					x=pow(10,i);
					flag=true;
					break;
				}
			}
			if(flag==true)
			printf("%lld\n",x);
		}
		else
		{
			min=cop[0];
			index=0;
			for(k=1;k<10;k++)
			{
				if(cop[k]<min)
				{
					min=cop[k];
					index=k;
				}
			}
			for(j=0;j<=min;j++)
			printf("%d",index);
			printf("\n");
		}
	}
	return 0;
}
