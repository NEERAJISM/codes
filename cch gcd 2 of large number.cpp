#include <iostream>
#include <cstdio>
using namespace std;

int findgcd(int n,int m)
{
    if(m==0)
        return n;
    else
        return findgcd(m,n%m);
}

int main()
{
    int tt,n,m,i,d,carry;
    string s;
    scanf("%d",&tt);

    while(tt--)
    {
        scanf("%d",&n);
        cin>>s;

        if( n==0 || (int)s[0]-(int)'0' == 0)
        {
            if(n==0)
                cout<<s<<endl;
            else
                printf("%d\n",n);
        }
        else
        {
            carry =0;
            for(i=0;i<s.size();i++)
                carry = (( (int)s[i]-(int)'0' + carry )%n )*10;

            int gcd = findgcd(n,carry/10);
            printf("%d\n",gcd);
        }
    }
return 0;
}
