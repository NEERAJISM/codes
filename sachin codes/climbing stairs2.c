
#include<stdio.h>


long long int fib[1000100];    // upto n=92 it is in the range of 10^19...long long int range

long long int fibonacci(int x)
{
	if(x==1)
	return 1;
	fib[1]=1;
	fib[2]=2;
	if(fib[x]!=0)
	return fib[x];
	else
	{
		fib[x]=fibonacci(x-1)+fibonacci(x-2);
		fib[x]=fib[x]%1000000007;
	}
	return fib[x];
}

int main()
{
	int t,n,g,i;
	fibonacci(10000);
	for(i=1;i<10000;i++)
	printf("%d   ",fib[i]);
return 0;
}
