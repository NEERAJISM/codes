#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int t,i,a1[26],a2[26],n,temp,sum;
    string s;

    scanf("%d",&t);

    while(t--)
    {
        for(i=0;i<26;i++)
        {
            a1[i] =0;
            a2[i] =0;
        }

        cin>>s;

        for(i=0;i<s.size();i++)
        {
            temp = (int) s[i];

            if(temp>=(int)'A' && temp<=(int)'Z')
                a1[temp-(int)'A']++;
            else
                a2[temp-(int)'a']++;
        }

        sum = 0;
        for(i=0;i<26;i++)
            sum+= a1[i]/2 + a1[i]%2 + a2[i]/2 + a2[i]%2;

        printf("%d\n",sum);
    }
return 0;
}
