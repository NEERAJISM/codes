#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;

int main()
{
    int t,i,d;

    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>d;
        v.push_back(d);
    }

    sort(v.begin(),v.end());

    vector<int>::iterator it= v.begin();
    for(it;it!=v.end();it++)
        cout<<*it<<endl;

    return 0;
}
