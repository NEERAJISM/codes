#include <iostream>
#include <cstdio>
int d[27],e[27],f[27];

using namespace std;
int main()
{
    string a,g,h,b,c;
    int flag1 = 0,flag2 = 0,i,j,count1=0,count2=0;
    cin>>a>>g>>h;

    if(g.size()>h.size())
    {
        b = h;
        c = g;
    }
    else
    {
        b = g;
        c = h;
    }

    for(i=0;i<a.size();i++)
        d[(int)(a[i]-96)]++;

    for(i=0;i<b.size();i++)
        e[(int)(b[i]-96)]++;

    for(i=0;i<c.size();i++)
        f[(int)(c[i]-96)]++;

    while(flag1+flag2 != 2)
    {
        if(flag1==0)
        {
            for(i=1;i<=26;i++)
            {
                if(d[i]<e[i])
                {
                    flag1 = 1;
                    break;
                }
            }

            if(flag1 != 1)
            {
                count1++;
                for(i=1;i<=26;i++)
                    d[i]=d[i]-e[i];
            }
        }
        else if(flag2==0)
        {
            for(i=1;i<=26;i++)
            {
                if(d[i]<f[i])
                {
                    flag2 = 1;
                    break;
                }
            }

            if(flag2 != 1)
            {
                count2++;
                for(i=1;i<=26;i++)
                    d[i]=d[i]-f[i];
            }
        }
    }

    if(count1 ==0 &&count2==0)
        cout<<a;
    else
    {
        while(count1--)
            cout<<b;

        while(count2--)
            cout<<c;

        for(i = 1;i<=26;i++)
        {
            while(d[i]--)
                cout<<(char)(i+96);
        }
    }

    return 0;
}
