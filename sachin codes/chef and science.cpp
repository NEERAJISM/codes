#include<iostream>
#include<stdio.h>
using namespace std;
int a[100003],b[100003];

int count_digits(int x)
{
	if(x==0)
	return 1;
	else
	{
		int c=0;
		while(x!=0)
		{
			x=x/10;
			c++;
		}
		return c;
	}
	
}

int find_digit(int y,int r)
{
	int z,i;
	int s=count_digits(y);
	r=s-r;
	for(i=1;i<=r;i++)
	{
		y=y/10;
	}
	z=y%10;
	return z;
}

int main()
{
	int n,m,k,l,v,i,j,pos,q,x,r,z,y,c,count;
	//cout<<count_digits(0)<<endl<<find_digit(0,1);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=count_digits(a[i]);
	}
	
	scanf("%d",&m);
    while(m--)
    {
    	scanf("%d%d%d",&l,&v,&k);
    	q=0;
    	count=0;
    	y=-1;
    	while((l+(q*v))<=n)
    	{
    		pos=l+(q*v);
    		x=a[pos-1];
    		c=b[pos-1];
    		count+=c;
    		if(count>=k)
    		{
    			y=x;
    			break;
    		}
    		q++;
    	}
    	if(y==-1)
    	printf("So sad\n");
    	else 
    	{
    		r=k-(count-c);
    		z=find_digit(y,r);
    		printf("%d\n",z);
    	}
    }
    return 0;
}
