#include<iostream>
using namespace std;

int main()
{
    int t,size1,i,j,k;
    char s[100000],w[100000];
    cin>>t;

    while(t-->0)
    {
        cin>>size1;
        cin>>w;
        cin>>s;

        w[1]=0;
        k=0;

        for(j=2;j<=size1;j++)
        {
            while(s[k+1]!=s[j])
                k=w[k];
            if(s[k+1]==s[j])
                k=k+1;

            w[j]=k;
        }

        for(i=0;i<size1;i++)
            cout<<w[i];
    }
    return 0;
}
