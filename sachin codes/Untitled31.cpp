#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
 
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
bool generator1(int n,unsigned sd,char s[])
{
	int p,i,c=0;
	srand1(sd);
	for(i=0;i<n;i++)
	{
		p=nextinteger1()%2;
		if(p!=s[i]-'0')
		{
			c=1;
			break;
		}
	}
	if(c==0)
	return true;
	else
	return false;
}
void srand2(unsigned sd)
{
	x=sd;
	y=x*sd;
	z=y*sd;
	w=z*sd;
}
unsigned nextinteger2()
{
	unsigned t=x^(x<<11);
	x=y;    y=z;    z=w;
	return w=(w^(w>>19))^(t^(t>>8));
}
bool generator2(int n,unsigned sd,char s[])
{
	int p,i,c=0;
	srand2(sd);
	for(i=0;i<n;i++)
	{
		p=nextinteger2()%2;
		if(p!=s[i]-'0')
		{
			c=1;
			break;
		}
	}
	if(c==0)
	return true;
	else
	return false;
}

 
int main()
{
	int t,n,i;
	char s[200003];
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		n=strlen(s);
	    for(i=0;i<=MAX;i++)
		{
			if(generator1(n,i,s))
			{
				printf("LCG\n");
				break;
			}
			else if(generator2(n,i,s))
			{
				printf("Xorshift\n");
				break;
			}
		}	
	}
	return 0;
}
