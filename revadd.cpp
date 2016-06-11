#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i,j,n1,n2,flag;
    string s1,s2;

    cin>>n;

    while(n--)
    {
        cin>>s1;
        cin>>s2;
        n1=0;
        n2=0;

        reverse(s1,0,s1.size()-1);
        reverse(s2,0,s2.size()-1);

        cout<<s1<<endl;
        cout<<s2<<endl;


        cout<<n1<<" "<<n2;

    }
    return 0;
}

