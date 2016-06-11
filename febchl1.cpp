#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i,chk,count1,count2,flag;
    string s;

    cin>>n;

    while(n-->0)
    {
        flag=0;
        cin>>s;
        count1=0;
        count2=0;
        chk='-';
        for(i=0;i<s.size();i++)
        {
            if(s[i]!=chk)
                count1++;

            if(chk=='-')
                chk='+';
            else
                chk='-';
        }

        chk='+';
        for(i=0;i<s.size();i++)
        {
            if(s[i]!=chk)
                count2++;

            if(chk=='-')
                chk='+';
            else
                chk='-';
        }

        count1=count1<count2?count1:count2;
        cout<<count1<<endl;
    }
    return 0;
}
