#include<iostream>
using namespace std;

long long int fib[34000];    // upto n=92 it is in the range of 10^19...long long int range

long long int a[100];

long long int fibonacci(int x)
{
	if(x==0)
	return 0;
	fib[0]=0;
	fib[1]=1;
	if(fib[x]!=0)
	return fib[x]; 
	else 
	fib[x]=(fibonacci(x-1)+fibonacci(x-2))%99991;
	return fib[x];
}

unsigned int generate_small(int k) {
    unsigned int res=1;
    for(int i=1; i<k; i++) {
        res<<=1;
        res|=1;
    }
    return res;
}

int main()
{
	int n,k,i,cur,temp,next,ans=0;
	fibonacci(33340);
	cin>>n>>k;
	for(i=0;i<n;i++)
	cin>>a[i];
	
//	cout<<fib[33328]<<"  "<<fib[33329]<<"  "<<fib[33330]<<" "<<fib[33331];
	cur=generate_small(k);
    unsigned int limit=1<<n;
    while(cur<limit) {
        long long int sum=0;
        for(int i=0; i<n; i++) {
            if(cur & (1<<i))
                sum=(sum+a[i]);
        }

        temp= cur | (cur-1);
        next=(temp+1) | (((~temp & -~temp)-1) >> (__builtin_ctz(cur)+1));
        cur=next;
        int s=(int)(sum%33330);
        ans=(ans+fib[s])%99991;
	}
	cout<<ans<<endl;
}
