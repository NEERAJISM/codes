#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,d;
    string s;
    float f;

    //add these two lines at the start but it will not output in the terminal  COUT WILL NOT WORK
    // while reading it will ignore the blank line
    //we need cout to print in output file
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>d;
        cout<<d<<" ";
    }

    cin>>s;
    cout<<endl<<s<<endl;

    cin>>f;
    cout<<f<<endl;
    return 0;
}
