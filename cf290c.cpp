#include<bits/stdc++.h>
using namespace std;
char c[100][100],a[26],temp[26];
int i,n,diff,j,d[27],flag;
int main()
{
    string s;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>s;

        for(j=0;j<s.size();j++)
            c[i][j]=s[j];
    }

    for(i=0;i<26;i++)
    {
        a[i]=(char)(97+i);
        d[i+1]=97+i;
    }

    for(i=0;i<n;i++)
    {

        if((int)c[i][j]<(int)c[i+1][j])
            i++;
        else if((int)c[i][j]>(int)c[i+1][j])
        {
            diff=(int)c[i][j]-(int)c[i+1][j];

            d[c[i][j]-96]=d[c[i][j]-96]-diff;
            d[c[i+1][j]-96]=d[c[i+1][j]-96]+diff;
        }
        else
        {
            if()
        }
    }

    return 0;
}
