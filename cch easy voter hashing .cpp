#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
    int n1,n2,n3,i,j,d;

    scanf("%d%d%d",&n1,&n2,&n3);
    map<int, int> mymap;

    for(i=0;i<n1+n2+n3;i++)
    {
        scanf("%d",&d);
        mymap[d]++;
    }

    map<int,int>::iterator it = mymap.begin();

    int county =0;

    for(it;it!=mymap.end();it++)
        if(it->second>=2)
            county++;

    printf("%d\n",county);

    for(it = mymap.begin();it!=mymap.end();it++)
    {
        if(it->second>=2)
            printf("%d\n",it->first);
    }
return 0;
}
