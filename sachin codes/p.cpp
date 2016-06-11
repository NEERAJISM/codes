#include<iostream>
using namespace std;

int main()
{
	int c=0;
	for(int i=2;i<=1000000008;i++)
	if(1000000000%i==0)
	c++;
	
	cout<<c;
	return 0;
}
