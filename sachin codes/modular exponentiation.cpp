#include<iostream>
#include<stdio.h>
using namespace std;

long long mulmod(long long int a,long long int b,long long int c)
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
}

long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y)%c;      //  or call  mulmod(x,y,c);
		}
		y=(y*y)%c;          //  or call  mulmod(y,y,c);
		b=b/2;
	}
	return x%c;
}

int main()
{
	long long int a,b,c,result;
	cout<<"enter a,b,c for (a^b)%c\n";
	cin>>a>>b>>c;
	result=modular_exponentiation(a,b,c);
	cout<<"answer is= "<<result<<endl;
	return 0;
}
