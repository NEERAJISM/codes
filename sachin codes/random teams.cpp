#include<iostream>
#include<stdio.h>
using namespace std;
long long int f(long long int x)
{
    long long int r;
	r=(x*(x-1))/2;
	return r;
}
int main()
{
	long long int n,m,a,b,c;
	long long int min,max;
	cin>>n>>m;
	a=n-m+1;
	b=n%m;
	c=n/m;
	min=(b)*f(c+1)+(m-b)*f(c);
	max=f(a);
	cout<<min<<" "<<max;
	return 0;
}
