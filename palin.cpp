#include<iostream>
using namespace std;
char s2[1000000];
int main()
{
    int t,n,n1,n2,flag,t1;
    string s;

    cin>>t;
    while(t-->0)
    {
        flag=0;
        cin>>s;
        n=s.size();

        if(n%2==0)
        {
            n1=n/2-1;
            n2=n1+1;
        }
        else
        {
            n1=n/2;
            n2=n1;
        }

        while(n1>=0||n2<n)
        {

            if(s[n1]==s[n2])
            {
                s2[n1]=s[n1];
                s2[n2]=s[n2];
                n1--;
                n2++;
            }
            else
            {
                flag=1;

                if(s[n1]>s[n2])
                {
                    //cout<<"n1 > n2\n";
                    while(n2<n)
                    {
                        s2[n2]=s[n1];
                        s2[n1]=s[n1];
                        n2++;
                        n1--;
                    }
                }
                else
                {
                    t1=(int)s[n1];
                    t1++;
                    s2[n1]=(char) t1;
                    s2[n2]=s2[n1];
                    n2++;
                    n1--;

                    //cout<<" n2 > n1\n";
                   // cout<<s2<<endl;

                    while(n1>=0)
                    {
                        s2[n2]=s[n1];
                        s2[n1]=s[n1];
                        n2++;
                        n1--;
                    }
                }
            }
        }

        //cout<<"flag "<<flag<<endl;

        if(flag==0)
        {
            if(n%2==0)
            {
                if(s[n/2-1]!='9')
                {
                    t1=(int)s[n/2-1];
                    t1++;
                    s2[n/2-1]=(char) t1;

                    t1=(int)s[n/2];
                    t1++;
                    s2[n/2]=(char) t1;
                }
                else
                {
                    s2[n/2-1]=='0'
                    s2[n/2]=='0'

                    t1=(int)s[n/2-2];
                    t1++;
                    s2[n/2-2]=(char) t1;

                    t1=(int)s[n/2];
                    t1++;
                    s2[n/2]=(char) t1;

                }
            }
            else
            {
                t1=(int)s[n/2];
                t1++;
                s2[n/2]=(char) t1;
            }
        }
        for(int i=0;i<n;i++)
            cout<<s2[i];

        cout<<endl;

    }
    return 0;
}
