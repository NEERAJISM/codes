#include <bits/stdc++.h>
using namespace std;

int comp(pair<int,int> p, pair<int,int> q)
{
    if(p.second > q.second)
        return 0;
    return 1;
}

int comp0(pair<int,int> p, pair<int,int> q)
{
    if(p.first > q.first || (p.first == q.first && p.second > q.second))
        return 0;
    return 1;
}

int main()
{
    int i,j,n,x,y,cnt = 0,tmp,flag;
    long long int rslt = 0;

    vector<pair<int,int> > v;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),comp0);

    i = 0;
    while(1)
    {
        tmp = 1;
        cnt = 1;
        while(1)
        {
            if((i>=v.size()-1) || (v[i].first != v[i+1].first))
                break;

            tmp+=1;
            i++;
        }

        if(tmp>1)
            rslt+= ((tmp*(tmp-1)/2));

        i++;
        if(i >= v.size()-1)
            break;
    }

    i=0;
    while(1)
    {
        j = i+1;
        cnt = 1;

        while(1)
        {
            if((j>=v.size()) || (v[i].first != v[j].first) || (v[i].second != v[j].second))
                break;

            j++;
            cnt++;
        }

        i = j;
        if(cnt>1)
            rslt-=(cnt*(cnt-1))/2;

        if(i >= v.size()-1)
            break;
    }

    sort(v.begin(),v.end(),comp);
    i = 0;
    while(1)
    {
        tmp = 1;
        while(1)
        {
            if((i>=v.size()-1) || (v[i].second != v[i+1].second))
                break;

            tmp+=1;
            i++;
        }

        if(tmp>1)
            rslt+= (tmp*(tmp-1)/2);

        i++;
        if(i >= v.size()-1)
            break;
    }

    printf("%lld\n",rslt);
    return 0;
}
