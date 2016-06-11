#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t,n,i,j,doubt,uneq;
    string s1,s2;
    scanf("%d",&t);
    while(t--)
    {
        doubt=0;
        uneq=0;

        cin>>s1>>s2;
        n= s1.size();

        for(i=0;i<n;i++)
        {
            if(s1[i]=='?' ||s2[i]=='?')
                doubt++;

            else if(s1[i]!=s2[i])
                uneq++;
        }
        printf("%d %d\n",uneq,uneq+doubt);
    }
return 0;
}
