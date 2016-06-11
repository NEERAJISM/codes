#include<iostream>
using namespace std;

long long int fib[100000];    // upto n=92 it is in the range of 10^19...long long int range

long long int fibonacci(int x)
{
	if(x==0)
	return 0;
	fib[0]=0;
	fib[1]=1;
	if(fib[x]!=0)
	return fib[x]; 
	else 
	fib[x]=fibonacci(x-1)+fibonacci(x-2);
	return fib[x];
}

int main()
{
	int n,i;
	cout<<"enter the number\n";
	cin>>n;
	fibonacci(n+1);
	
	cout<<fib[n]<<"  ";
	return 0;
}
