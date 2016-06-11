#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,j,seach,flag,x,k1,nk;
    string s;

    cin>>s;
    n= s.size();

    cin>>k;

    seach = n/k-1;
    k1 = k;
    nk =n/k;
    flag = 0;
    i = 0;

    if(n%k>0)
        cout<<"NO";
    else
    if(nk%2==0)
    {
        while(k1--)
        {
            j=0;
            for(j ; j <nk/2 ;j++)
            {
                if( s[i+j] != s[seach-j] )
                {
                    //cout<<s[i+j]<<i+j<<" "<<s[seach-j]<<seach-j<<endl;
                    flag=1;
                    break;
                }
            }

            if(flag==1)
                break;

            i = seach+1;
            seach = seach+nk;

        }

        if(flag==0)
            cout<<"YES";
        else
            cout<<"NO";
    }
    else
    {
        while(k1--)
        {
            j=0;

            for(j ; j <=nk/2 ;j++)
            {
                if( s[i+j] != s[seach-j] )
                {
                    //cout<<s[i+j]<<i+j<<" "<<s[seach-j]<<seach-j<<endl;
                    flag=1;
                    break;
                }
            }

            if(flag==1)
                break;

            i = seach+1;
            seach = seach+nk;

        }

        if(flag==0)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
