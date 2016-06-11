#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[26],flag = 0;
    string s;
    cin>>n>>s;

    for(int i=0;i<n;i++)
    {
        if((int)s[i]>= 'A' && (int)s[i]<='Z')
        {
            a[(int)s[i]-65]=1;
        }
        else
        {
            a[(int)s[i]-97]=1;
        }
    }

    for(int i=0;i<26;i++)
    {
        if(a[i]!=1)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;

}
