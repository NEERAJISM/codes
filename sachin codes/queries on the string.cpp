#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	char a[100002];
	int n,m,i,s,c,k,x,y,z,j;
	scanf("%d%d",&n,&m);
	cin>>a;
	for(k=0;k<m;k++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)
		a[y-1]=z;
		else
		{
			c=0;
			for(i=y-1;i<z;i++)
			{
				s=0;
				for(j=i;j<z;j++)
				{
					s+=(a[j]-'0');
					if(s%3==0)
					c++;
				}
			}
			printf("%d\n",c);
		}
	}
	return 0;
}
