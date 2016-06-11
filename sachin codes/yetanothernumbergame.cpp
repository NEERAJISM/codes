#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	long long int t;
	cin>>n;
	while(n--)
	{
		cin>>t;
		if(t&1)
		cout<<t-1<<"\n";
		else
		cout<<t<<"\n";
	}
	return 0;
}
