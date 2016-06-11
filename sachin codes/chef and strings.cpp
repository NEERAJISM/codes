#include<bits/stdc++.h>
using namespace std;
int a[10][1000003];
char s[1000003];

void func()
{
	int i,L,x1,x2,x3,x4,k1=0,k2=0,k3=0,k4=0;
	L=strlen(s);
	x1=int('c')-98;	x2=int('h')-98;	x3=int('e')-98;	x4=int('f')-98;

	for(i=0;i<L;i++)
	{
		if(s[i]=='c')
		{
			
			a[x1][k1]=i;
			k1++;
		}
		if(s[i]=='h')
		{
		
			a[x2][k2]=i;
			k2++;
		}
		if(s[i]=='e')
		{
		
			a[x3][k3]=i;
			k3++;
		}
		if(s[i]=='f')
		{
		
			a[x4][k4]=i;
			k4++;
		}
	}
	a[x1][k1++]=-1; a[x2][k2++]=-1;	a[x3][k3++]=-1;	a[x4][k4++]=-1;
}

int main()
{
	char c,d;
	int q,l,r,i,sum;
	gets(s);
	func();
	scanf("%d",&q);
	while(q--)
	{
		cin>>c>>d;
		scanf("%d%d",&l,&r);
		x=int(c)-98;  y=int(d)-98;
		count=0;
		for(i=0;i<k;i++)
		{
			if(a[y][i]>=l-1&&a[y][i]<=r-1)
			count++;
		}
		
		printf("%d\n",sum);
	}
	return 0;
}
