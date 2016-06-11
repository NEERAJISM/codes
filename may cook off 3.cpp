#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,n,a[27],diff,temp[27][2],k,same;
    string s;
    char s2[100000],t2;
    cin>>t;

    while(t--)
    {
        k=0;

        for(i=1;i<=26 ;i++)
            a[i] =0;

        cin>>s;
        n=s.size();

        for(i=0 ; i<n ; i++)
        {
            a[s[i]-'a'+1]++;
            s2[i] = '\0';
        }

        same = 0;
        for(i=1;i<=26;i++)
        {
            if(a[i]!=0)
            {
                temp[k][0]=i;
                temp[k][1] =a[i];
                if(a[i]>same)
                    same  = a[i];
                k++;
            }
        }

        if((n%2==0 && same>=n/2+1)||(n%2==1 && same>=n/2+2))
            cout<<"-1"<<endl;
        else
        {
            int size1 = 0,mag,si,i=0;

            while(size1 < n)
            {
                mag =0;
                for(int i1=0 ; i1<k ; i1++)
                    if(temp[i1][1] > mag)
                    {
                        mag = temp[i1][1];
                        si = i1;
                    }

                t2 = (char)(temp[si][0] + 96);
                size1 = size1 + mag;
                temp[si][1] = -1;

                for(i ; mag>0 ; mag--)
                {
                    if(i>=n)
                    {
                        for(i=0 ; i<n ; i++)
                            if(s2[i]=='\0')
                                break;
                    }

                    if(s2[i] != '\0')
                        for(i=0 ; i<n ; i++)
                            if(s2[i]=='\0')
                                break;

                    s2[i] = t2;

                    i+=2;
                }
            }

            for(i=0;i<n;i++)
                cout<<s2[i];

            cout<<endl;
        }
    }
    return 0;
}
