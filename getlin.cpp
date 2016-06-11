#include<bits/stdc++.h>
using namespace std;
map<string,int>m;

int main()
{
    map<string,int>::iterator it=m.begin(),it2;;

    int i=0,d;
    string s;
    for(i=0;i<7;i++)
    {
        cin>>s;
        cin>>d;
        it2=m.find(s);

        m.insert(make_pair(s,d));
    }


    for(it;it!=m.end();it++)
        cout<<(*it).first<<" "<<(*it).second<<endl;

    return 0;
}
