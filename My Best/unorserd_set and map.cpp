#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> m;
    int s;
    for(i=0;i<5;i++)
    {
        cin>>s;
        m.insert(s);
    }

    for(auto it : m)
        cout<<*it.first<<endl;
}
