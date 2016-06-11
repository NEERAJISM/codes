#include<bits/stdc++.h>
using namespace std;

char s[100003];
int a[3000][3000];
int b[100003][27];

/*int solve(int l,int r,int type)
{
	int c=0,count=0;
	for(int i=l;i<=r;)
	{
		if(s[i]==s[i+1]&&i!=r)
		{
			c++;
			i=i+2;
			count+=c;
		}
		else
		{
			i++;
			c=0;
		}
	}
	printf("%d\n",count);
	return count;
}
*/

int func()
{
	int i,j,x,n;
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=25;j++)
		{
			b[i+1][j]=b[i][j];
		}
		x=(int)(s[i]-'a');
		b[i+1][x]++;
	}
	/*for(i=0;i<=n;i++)
	{
		for(j=0;j<=25;j++)
		cout<<b[i][j]<<"  ";
		cout<<endl;
	}*/
}

int solve(int l,int r,int type)
{
	int i,j,k,x,flag;
	int count=0;
	
	for(i=l;i<=r;i++)
	{
		for(j=i+1;j<=r;j++)
		{
			flag=0;
			for(k=0;k<=25;k++)
			{
				x=b[j][k]-b[i-1][k];
				if(x%2==1)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			count=count+pow((j-i+1),type);
		}
	}
	printf("%d\n",count);
	return count;
}

int main()
{
	int t,n,q,x,y,type,i,j,L,R;
	
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		n=strlen(s);
		int A=0,B=0,ans;
		
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=25;j++)
			{
				b[i][j]=0;
			}

		}
		
		scanf("%d",&q);
		func();
		
		while(q--)
		{
			scanf("%d%d%d",&x,&y,&type);
			
			L = ( x + A ) % n + 1; 
        	R = ( y + B ) % n + 1;
        	if(L>R)
        	{
        		int qq=L;
        		L=R;
        		R=qq;
        	}
        	ans=solve(L,R,type);
        	A=B;
        	B=ans;
		}
	}
	return 0;
}
