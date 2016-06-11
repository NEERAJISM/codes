#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int n,i,temp,maxlength = 1,j,length,current;
    scanf("%d",&n);
    vector< vector<int> > v(n+3);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&temp);

        if(temp != -1)
            v[i].push_back(temp);
    }

    for(i=1;i<=n;i++)
    {
        if(v[i].size()>0)
        {
            current = i;
            length=1;
            //cout<<current<<"**"<<endl;

            while(v[current].size()>0)
            {
                current = v[current][0];
                //cout<<current<<"*****"<<endl;
                length++;
            }

            if(maxlength < length)
                maxlength =length;
        }
    }

    printf("%d\n",maxlength);
return 0;
}
