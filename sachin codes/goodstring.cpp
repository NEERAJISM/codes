#include<iostream>
#include<string.h>
using namespace std;
int fun(char c[])
{ int g,h=0;
for(g=0;g<strlen(c);g++)
{
	if(c[g]=='a')
		h++;
}
	return h;
}

int function(char c[],int ne)
{
	int l,pos,j,n;
	char d[100000];
	int y=fun(c);
	if(y==0)
	{
		return ne;
		
	}
	else
	{
	for(j=0;j<strlen(c);j++)
	{
		if(c[j]=='a')
		 {
		 pos=j; break;}
	}
	int i=0;
	while(c[pos+i]=='a')
	{
		i++;
	};
	if(ne>=i)
	{n=ne;}
	else
	{n=i;}
	l=strlen(c);
	for(j=(pos+i+1);j<l;j++)
	{
		d[j-(pos+i+1)]=c[j];
	}
	function(d,n);
	}
}
int main()
{
	char c[100000];
	int j;
	cin>>c;
	int h=fun(c);
	if(h==0)
	{
		cout<<'a';
	}
	else
	{
		int z=function(c,0);
	for(j=0;j<=z;j++)
	{
		cout<<'a';
	}
	
	}
	
	return 0;
}
