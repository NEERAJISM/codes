#include<iostream>
using namespace std;
#include<vector>
 
/* This function calculates power of p in n! */
long long int countFact(long long int n, long long int p)
{
    long long int k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}
 
/* This function calculates (a^b)%MOD */
long long int pow(long long int a, long long int b, long long int MOD)
{
    long long int x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}/*
long long int factMOD(long long int n, long long int MOD)
{
    long long int res = 1;
    while (n > 1)
    {
        long long int cur = 1,i;
        for (i=2; i<MOD; ++i)
            cur = (cur * i) % MOD;
        res = (res * pow (cur, n/MOD, MOD)) % MOD;
        for (i=2; i<=n%MOD; ++i)
            res = (res * i) % MOD;
        n /= MOD;
    }
    res=res % MOD;
    return res;
}*/
long long factMOD2(int n, int MOD)
{
    long long res = 1,i,m; 
    while (n > 0)
    {
        for (i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0) 
            res = MOD - res;
    }
    return res;
}
int main()
{
	long long int n,m,x;
	cin>>n>>m;
	x=factMOD2(n,m);
	cout<<x;
	return 0;
}
