#include<iostream>
#include<string>
using namespace std;
long long int a[26],f;
string s;
long long int fact(int x)
{
    if(x==1)
        return 1;
    else
        f=x*fact(x-1)%1000000007;

    return f;
}
int main()
{
    long long int t,n,i,ans,div;

    cin>>s;

    while(t-->0)
    {
        cin>>s;
        div=1;
        for(i=0;i<s.size();i++)
            a[s[i]-97]++;

        for(i=0;i<26;i++)
        {
            if(a[i]>1)
               div=div*fact(a[i]);
            a[i]=0;
        }
        ans=fact(s.size())/div;

        cout<<ans<<endl;

    }
    return 0;
}
