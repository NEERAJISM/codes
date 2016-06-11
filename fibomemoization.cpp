#include<iostream>
using namespace std;
long long int f1[100];
long long int fibo(int n)
{
    if(n==0||n==1)
        return n;

    if(f1[n]!=-1)
        return f1[n];
    else
    {
        f1[n]=fibo(n-1)+fibo(n-2);
        return f1[n];
    }
}

int main()
{
    long long int n;
    for(int i=0;i<100;i++)
        f1[i]=-1;

    cin>>n;
    cout<<fibo(n);

    return 0;
}
