#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,w,lead = 0,s1=0,s2=0,c1,c2;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c1>>c2;
        s1+=c1;
        s2+=c2;

        if(s1-s2 > lead || s2-s1 >lead)
        {
            if(s1>s2)
            {
                w=1;
                lead = s1-s2;
            }
            else
            {
                w=2;
                lead = s2- s1;
            }
        }
    }
    cout<<w<<" "<<lead;
    return 0;
}
