#include<iostream>
#include<stdio.h>
using namespace std;
class p
{
    int n,m;
public:	p(int x1,int x2)
        { n=x1; m=x2;}
	 
	        friend int miinus(p h);
};
int miinus(p h)
{
	return (h.n-h.m);
}

int main()
{
	int c,a,b;
	cout<<"enter the numbers\n";
	cin>>a>>b;
	p f(a,b);
    	c=miinus(f);
	cout<<"minus is  "<<c;
	return 0;
}
