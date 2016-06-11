#include<iostream>
#include<stdio.h>
using namespace std;
class p
{

	
	public: int n,m;
	        friend int minus(p g);
};
int minus(p h)
{
	return (h.n-h.m);
}

int main()
{
	int c;
	p f;
	cout<<"enter the numbers\n";
	cin>>f.n>>f.m;
	c=minus(f);
	cout<<"minus is  "<<c;
	return 0;
}
