#include <bits/stdc++.h>
#include <iterator>
using namespace std;
int main()
{
    int i,j,q,d,vli,vle,nl,mid,l,r;
    char cc;
    set<int> s;
    set<int>::iterator it;

    scanf("%d",&q);
    while(q--)
    {
        cin>>cc;
        scanf("%d",&d);
        if(cc == 'I')
            s.insert(d);
        else if(cc == 'D')
        {
            it = s.find(d);
            if(it != s.end())
                s.erase(it);
        }
        else if(cc == 'K')
        {
            if(d > s.size())
                printf("invalid\n");
            else
            {
                d-=1;
                it = s.begin();
                advance(it,d);
                printf("%d\n",*(it));
            }
        }
        else
        {
            vli = *(s.begin());
            it = s.end();
            it--;
            vle = *it;

            if(d > vle)
                printf("%d\n",s.size());
            else if(d < vli)
                printf("0\n");
            else
            {
                it = s.find(d);
                if(it != s.end())
                    printf("%d\n",distance(s.begin(),it)+1);
                else
                {
                    vector<int> v(s.begin(),s.end());
                    nl = v.size();

                    mid = (nl-1)/2;
                    l = 0;
                    r = nl-1;

                    while(1)
                    {
                        if(v[mid]>d && v[mid-1]<d)
                            break;

                        if(v[mid]<d)
                            l = mid+1;
                        else
                            r = mid-1;

                        mid= (l+r)/2;
                    }
                    printf("%d\n",mid);
                }
            }
        }
    }
    return 0;
}
