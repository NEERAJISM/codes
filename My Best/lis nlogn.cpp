#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ttt,i,j,x,y,k,m,n,q,d,flag=  0,mx = 0,prev = -1,num,res = 0;

    set<int> st;
    set<int>::iterator it;

    for(i=0;i<5;i++)
    {
        cin>>d;
        st.insert(d);
        it= st.find(d);
        it++;
        if(it!=st.end())
            st.erase(it);
    }
    return 0;
}
