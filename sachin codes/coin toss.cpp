#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


long long int fib[10000003];


int main()
{
	int t;
	long long int k,x;
	
	fib[1]=2; fib[2]=3;
	for(int i=3;i<=10000000;i++)
	fib[i]=(fib[i-1]+fib[i-2])%MOD;
	
	scanf("%d",&t);
	while(t--)
	{
		cin>>k;
		if(k==1)
		x=0;
		else if(k==2||k==3)
		x=1;
		else
		{
			x=fib[k-3];
				
		}
		cout<<x<<endl;
	}
	return 0;
}
