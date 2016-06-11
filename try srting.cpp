#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n;
    char s[100000];
    cin>>n;
    scanf("%s",&s);

    for(int j=0;j<n-1;j++)
    {string s1(s+j,s+j+1);
    cout<<s1<<endl;;
    }
    return 0;

}
