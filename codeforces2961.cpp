#include<iostream>
using namespace std;
int main()
{
     long long int a,b,count=0,t;

     cin>>a>>b;

     while(1)
     {
        count=count+a/b;

        t=a%b;
        if(t==0)
            break;

        a=b;
        b=t;
     }

     cout<<count;
     return 0;
}
