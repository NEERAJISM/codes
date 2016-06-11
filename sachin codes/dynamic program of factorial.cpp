#include<iostream>
using namespace std;

long long int fac[100000];    // after n=22 it goes out of range

long long int factorial(int x)
{
	if(x==0||x==1)
	return 1;
	fac[0]=1;
	fac[1]=1;
	if(fac[x]!=0)
	return fac[x];
	else 
	fac[x]=(x*factorial(x-1))%1000000007;
	return fac[x];
}

int main()
{
	int n,i;
	cout<<"enter the number\n";
	cin>>n;
	for(i=1;i<=n;i++)
	cout<<factorial(i)<<"  ";
	return 0;
}
