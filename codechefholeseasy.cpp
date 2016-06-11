#include<iostream>
using namespace std;
int main()
{
    int t,holes;
    string s;

    cin>>t;
    while(t--)
    {
        cin>>s;
        holes = 0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='B')
                holes+=2;
            else if(s[i]=='A'||s[i]=='D'||s[i]=='O'||s[i]=='P'||s[i]=='Q'||s[i]=='R')
                holes++;
        }

        cout<<holes<<endl;
    }
return 0;
}
