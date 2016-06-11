#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a[10][10];

int main()
{
a[0][1]=1;
a[0][4]=1;
a[0][5]=1;
a[1][0]=1;
a[1][6]=1;
a[1][2]=1;
a[2][1]=1;
a[2][7]=1;
a[2][3]=1;
a[3][2]=1;
a[3][8]=1;
a[3][4]=1;
a[4][3]=1;
a[4][9]=1;
a[4][0]=1;
a[5][0]=1;
a[5][7]=1;
a[5][8]=1;
a[6][1]=1;
a[6][8]=1;
a[6][9]=1;
a[7][2]=1;
a[7][5]=1;
a[7][9]=1;
a[8][3]=1;
a[8][5]=1;
a[8][6]=1;
a[9][4]=1;
a[9][6]=1;
a[9][7]=1;
	int t,i,l,x,y,z,count;
	char c[100002];
	scanf("%d",&t);
	while(t--)
	{
		cin>>c;
		int b[100002]={-1};
		l=strlen(c);
		count=0;
		for(i=0;i<l;)
		{
			if(i==l-1)
			{
				if(b[i]!=-1)
				break;
				else 
				{
					int f=c[i]-'A';
					if(a[b[i-1]][f]==1)
					b[i]=f;
					else if(a[b[i-1]][f+5]==1)
					b[i]=f+5;
					else
					break;
					break;
				}
			}
			else
			{
			
			x=c[i]-'A';
			y=c[i+1]-'A';
			
			if(x!=y)
			{
				if(b[i]!=-1)
				{
				
				    if(a[b[i]][y]==1)
			     	{
			     		b[i+1]=y;
				       i++;
			     	}
			     	else if(a[b[i]][y+5]==1)
			     	{
			     		b[i+1]=y+5;
				       i++;
			     	}
				   else
				   {
					  count++;
					   break;
				   }
				}
				else
				{
					if(a[x][y]==1)
				    {
				    	b[i]=x;
				    	b[i+1]=y;
				        i++;
				    }
				    else if(a[x+5][y]==1)
				    {
				    	b[i]=x+5;
				    	b[i+1]=y;
				    	i++;
				    }
				    else if(a[x][y+5]==1)
				    {
				    	b[i]=x;
				    	b[i+1]=y+5;
				        i++;
				    }
				    else if(a[x+5][y+5]==1)
				    {
				    	b[i]=x+5;
				    	b[i+1]=y+5;
				    	i++;
				    }
				    else
				    {
					   count++;
					   break;
				    }
				}
			}
			else if(x==y&&i+2<l)
			{
				z=c[i+2]-'A';
				if(a[y+5][z]==1)
				{
					b[i]=x;
				    b[i+1]=x+5;
				    b[i+2]=z;
				    i=i+2;
				}
				else if(a[y+5][z+5]==1)
				{
					b[i]=x;
				    b[i+1]=x+5;
				    b[i+2]=z+5;
				    i=i+2;
				}
				else if(a[y][z]==1)
				{
					b[i]=x+5;
					b[i+1]=x;
					b[i+2]=z;
					i=i+2;
				}
				else if(a[y][z+5]==1)
				{
					b[i]=x+5;
					b[i+1]=x;
					b[i+2]=z+5;
					i=i+2;
				}
				else
				{
					count++;
					break;
				}
			}
			else
			{
				break;
			}}
		}
		if(count!=0)
		printf("-1\n");
		else
		for(i=0;i<l;i++)
		printf("%d",b[i]);
		printf("\n");
	}
	return 0;
}
