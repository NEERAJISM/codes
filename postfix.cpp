#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int t,n,top1,top2;
    string s;
    char s1[400],s2[400];
    cin>>t;

    while(t-->0)
    {
        top1=0;
        top2=0;
        cin>>s;
        n = s.size();

        for(int i=0;i<n;i++)
        {
            //cout<<i<<endl;
            if(s[i]=='(')
            {
               // cout<<"lp"<<endl;
                s1[top1]=s[i];
                top1++;
            }
            else if((int)s[i]>=97&&(int)s[i]<=122)
            {

                s2[top2]=s[i];
               // cout<<s2[top2]<<"/*\n";
                top2++;
            }
            else if(s[i]==')')
            {

                top1--;
                while(s1[top1]!='(')
                {
                    s2[top2]=s1[top1];
                   // cout<<s2[top2]<<"/*\n";
                    top1--;
                    top2++;
                }
            }
            else
            {

                if(s[i]=='^')
                {
                    top1--;
                    while(s1[top1]=='^'&&top1>=0)
                    {
                        s2[top2]=s1[top1];
                        top2++;
                        top1--;
                    }

                    top1++;
                    s1[top1]='^';
                    top1++;

                }
                else if(s[i]=='*'||s[i]=='/')
                {
                    top1--;
                    while((s1[top1]=='^'||s1[top1]=='*'||s1[top1]=='/')&&top1>=0)
                    {
                        s2[top2]=s1[top1];
                        //cout<<s2[top2]<<"/*\n";
                        top2++;
                        top1--;
                    }

                    top1++;
                    if(s[i]=='*')
                        s1[top1]='*';
                    else
                        s1[top1]='/';
                    top1++;
                }
                else
                {
                    top1--;
                    while((s1[top1]=='^'||s1[top1]=='*'||s1[top1]=='/'||s1[top1]=='+'||s1[top1]=='-')&&top1>=0)
                    {
                        s2[top2]=s1[top1];
                       // cout<<s2[top2]<<"/*\n";
                        top2++;
                        top1--;
                    }

                    top1++;
                    if(s[i]=='+')
                        s1[top1]='+';
                    else
                        s1[top1]='-';
                    top1++;
                }
            }
        }
        top1--;
        while(top1>=0)
        {
            s2[top2]=s1[top1];
            top2++;
            top1--;
        }

        for(int i=0;i<top2;i++)
            cout<<s2[i];

        cout<<endl;

    }
    return 0;
}
