#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;
long long int c[100005];

long long int power(long long int d)
{
    long long int t;
    if(c[d]!=0)
        return c[d];
    else
    {
        if(d == 0)
            return 1;
        else
        {
            if(d%2>0)
                return (2*power(d-1))%mod;

            t= power(d/2)%mod;
            return (t*t)%mod;
        }
    }
}

int main()
{
	long long int t1,a[100000],n,i,j,sum;
	cin>>t1;

	while(t1--)
	{
		sum = 0;
		cin>>n;

		for (i = 0; i < n; ++i)
			cin>>a[i];

		sort(a,a+n);

        //for (int i = 0; i < n; ++i)
			//printf("%d ",a[i]);
		for (i = 0; i < n; ++i)
		{

            c[i] = power(i);
            c[n-i-1] = power(n-i-1);

            sum = sum + (a[i]*(c[i] - c[n-1-i]))% mod;
            sum = sum % mod;
		}
		//cout<<"*****"<<endl;
        cout<<sum<<endl;
	}
	return 0;
}
