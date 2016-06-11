#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int tt,n,i;
    string s;
    scanf("%d",&tt);

    while(tt--)
    {
        cin>>s;
        n= s.size();

        vector<int> va(27,0);
        vector<int> vb(27,0);

        int tr=n/2;

        for(i=0;i<tr;i++)
        {
            va[(int)s[i]-(int)'a']++;
        }

        if(n%2==0)
            i=tr;
        else
            i=tr+1;

        for(i;i<n;i++)
        {
            vb[(int)s[i]-(int)'a']++;
        }
        int flag=0;
        for(i=0;i<26;i++)
        {
            if(va[i] != vb[i])
            {
                flag =1;
                break;
            }
        }

        if(flag == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
return 0;
}
