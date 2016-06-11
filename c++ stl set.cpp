#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    multiset<pair<int,char>> myset;

    myset.insert(make_pair(5,'k'));
    myset.insert(make_pair(2,'d'));
    myset.insert(make_pair(3,'s'));
    myset.insert(make_pair(8,'n'));

    cout<<myset.size()<<endl;

    multiset<int>::iterator it = myset.begin();

    for(it;it!=myset.end();it++)
    {
        cout<<*it.first<<endl;
    }

    myset.insert(5);
    it= myset.begin();
    for(it;it!=myset.end();it++)
    {
        cout<<*it<<endl;
    }
return 0;
}
