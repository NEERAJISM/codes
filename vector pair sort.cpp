#include <iostream>
#include <cstdio>
#include <map>
#include <iterator>
using namespace std;
int main()
{
    map<int,char> s;
    s.insert(make_pair(2,'s'));
    s.insert(make_pair(5,'a'));
    s.insert(make_pair(1,'x'));

    map<int,char>::iterator it;
    for(it = s.begin();it!=s.end();it++)
    {
        cout<<it->first<<it->second<<endl;
    }
return 0;
}
