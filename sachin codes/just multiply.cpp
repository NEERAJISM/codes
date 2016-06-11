#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;


/*long long mulmod(long long int a,long long int b,long long int c)
{
	long long int x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x+y)%c;
		}
		y=(y+y)%c;
		b=b/2;
	}
	return x%c;
}*/
long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y)%c;
		}
		y=(y*y)%c; 
		b=b/2;
	}
	return x%c;
}
long long int process(long long int a[],int l,long long int m)
{
	int i;
	long long int p,r;
	p=a[0];
	for(i=0;i<(l-1);i++)
	{
		r=p%m; //cout<<"r="<<r;
		p=(r*10)+a[i+1];//cout<<"p="<<p;
	}
	return p%m;;
}


int main()
{
	int t,i,l,k,j,count;
	long long int m,x,y,z,a[10000],res,X,Y,b[10000],d[10000];
	char c[10003];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&m);
		cin>>c;
		l=strlen(c);

		i=0; count=0;
		while(i<l)
		{
			j=0;x=0;
			while(c[i+j]!='*' &&(i+j)<l)
			{
				X=int(c[i+j]-'0');
				b[j]=X;
				j++;
			}
			x=process(b,j,m);//cout<<"x="<<x;
			i=i+j+2;
			
			k=0;y=0;
			while(c[i+k]!='*' &&(i+k)<l)
			{
				Y=int(c[i+k]-'0');
				d[k]=Y;
				k++;
			}
			y=process(d,k,m);//cout<<"y="<<y;cout<<"k="<<k;
			if(k==0)
			{
				
				a[count++]=x;break;
			}
			z=modular_exponentiation(x,y,m);//cout<<"z="<<z<<endl;
			a[count++]=z;
			
			i=i+k+1;
		}
		res=1;//cout<<"ass";
		for(i=0;i<count;i++)
		{
			res=(a[i]*res)%m;
		}
		printf("%lld\n",res);
	}
	return 0;
}
