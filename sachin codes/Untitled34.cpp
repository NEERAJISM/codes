#include<bits/stdc++.h>
using namespace std;
#define MAX 32767
 
unsigned X,x,y,z,w;
 
void srand1(unsigned sd)
{
	X=sd;
}
unsigned nextinteger1()
{
	X=X*1103515245+12345;
  return (X/65536)%32768;
}


int main()
{
	int t,n,i,j,count;
	int a[MAX+2];
	char s[200003];
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		n=strlen(s);
		int flag=0;
	    for(i=0;i<=MAX;i++)
		{
			srand1(i);
			a[i]=nextinteger1();
		}
		for(i=0;i<=MAX;i++)
		{
			x=a[i]%2;
			count=0;
			for(j=0;j<n;j++)
			{
				if(x!=s[j])
				break;
				else
				{
					count++;
					y=a[i];
					x=a[y]%2;
				}
			}
			if(count==n)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		printf("LCG\n");
		else
		printf("Xorshift\n");
	}
	return 0;
}
