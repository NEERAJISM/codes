#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    string s;
    cin>>i;
    stringstream ss;

    //int to string
    ss<<i;
    s = ss.str();
    cout<<s<<endl;

    //to clear buffer
    ss.clear();
    ss.str("");

    //string to int
    cin>>s;
    ss.str(s);
    ss >> i;
    cout<<i;
}
