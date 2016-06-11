#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,type,n,cost,i,t1,a,b,flag,cost2,j,t2;
    string s;
    cin>>t;

    while(t--)
    {
        cin>>type;
        cin>>s;

        n=s.size();

        t1=0;
        cost=0;
        cost2=0;
        for(i=0;i<n;i++)
            if(s[i]=='B')
                t1++;

        if(n%2==1)                                                  //odd
        {
           // cout<<"/*/*1 VALID\n";
            if(t1-n/2-1==0||t1-n/2-1==-1)
            {
                if(t1>n/2)
                {
                    for(i=0;i<n;i++)
                    {
                        if(i%2==0&&s[i]!='B'||i%2==1&&s[i]!='G')    //BGBGBGBG
                        {
                          //  cout<<"1 "<<i<<"**"<<endl;
                            a=i;
                            if(s[a]=='G')
                            for(j=i+1;j<n;j+=2)
                            {
                                if(s[j]!='G')
                                {
                                    if(type==0&&a-j!=0)
                                    {
                                        s[a]='B';
                                        s[j]='G';
                                        cost++;
                                    }
                                    else if(type!=0)
                                    {
                                        s[a]='B';
                                        s[j]='G';
                                        cost =cost+(pow(abs(a-j),type));
                              //          cout<<s<<endl;
                                        break;
                                    }
                                }
                            }
                            else
                                for(j=i+1;j<n;j+=2)
                                {
                                    if(s[j]!='B')
                                    {
                                        if(type==0&&a-j!=0)
                                        {
                                            s[a]='G';
                                            s[j]='B';
                                            cost++;
                                        }
                                        else if(type!=0)
                                        {
                                            s[a]='G';
                                            s[j]='B';
                                            cost =cost+(pow(abs(a-j),type));
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        cout<<cost<<endl;
                    }
                    else
                    {
                        for(i=0;i<n;i++)
                        {
                            if(i%2==0&&s[i]!='G'||i%2==1&&s[i]!='B')    //GBGBGBGB
                            {
                            //    cout<<"2 "<<i<<"**"<<endl;
                                a=i;
                                if(s[a]=='B')
                                for(j=i+1;j<n;j+=2)
                                {
                                    if(s[j]!='B')
                                    {
                                        if(type==0&&a-j!=0)
                                        {
                                            s[a]='G';
                                            s[j]='B';
                                        //    cout<<s<<endl;
                                            cost++;
                                        }
                                        else if(type!=0)
                                        {
                                            s[a]='G';
                                            s[j]='B';
                                      //      cout<<s<<endl;
                                            cost =cost+(pow(abs(a-j),type));
                                            a=-1;
                                            break;
                                        }
                                    }
                                    //cout<<cost<<endl;
                                }
                                else
                                for(j=i+1;j<n;j+=2)
                                {
                                    if(s[j]!='G')
                                    {
                                        if(type==0&&a-j!=0)
                                        {
                                            s[a]='B';
                                            s[j]='G';
                                            cost++;
                                        }
                                        else if(type!=0)
                                        {
                                            s[a]='B';
                                            s[j]='G';
                                            cost =cost+(pow(abs(a-j),type));
                                            a=-1;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        cout<<cost<<endl;
                }
            }
            else
                cout<<"-1\n";
        }
        else
        {
            if(abs(t1-n/2)==0)
            {
                //cout<<"valid\n";
                for(i=0;i<n;i++)
                {
                    if(i%2==0&&s[i]=='G'||i%2==1&&s[i]=='B')    //BGBGBGBG
                    {
                        //cout<<"1 "<<i<<"**"<<endl;
                        a=i;
                        if(s[a]=='G')
                        for(j=i+1;j<n;j=j+2)
                        {
                            if(s[j]=='B')
                            {
                                if(type==0&&a-j!=0)
                                {
                                    s[a]='B';
                                    s[j]='G';
                                    cost++;
                                }
                                else if(type!=0)
                                {
                                    s[a]='B';
                                    s[j]='G';
                                    cost =cost+(pow(abs(a-j),type));
                                    break;
                                }
                            }
                        }
                        else
                        for(j=i+1;j<n;j=j+2)
                        {
                            if(s[j]=='G')
                            {
                                if(type==0&&a-j!=0)
                                {
                                    s[a]='G';
                                    s[j]='B';
                                    cost++;
                                }
                                else if(type!=0)
                                {
                                    s[a]='G';
                                    s[j]='B';
                                    cost =cost+(pow(abs(a-j),type));
                                    a=-1;
                                    break;
                                }
                            }
                        }
                    }
                }
                //cout<<"1cost "<<cost<<endl;
                for(i=0;i<n;i++)
                {
                    if(i%2==0&&s[i]=='B'||i%2==1&&s[i]=='G')    //GBGBGBGB
                    {
                       //cout<<"2 "<<i<<"**"<<endl;
                        a=i;
                        if(s[a]=='B')
                        for(j=i+1;j<n;j=j+2)
                        {
                            if(s[j]=='G')
                            {
                                if(type==0&&a-j!=0)
                                {
                                    s[a]='G';
                                    s[j]='B';
                                    cost2++;
                                }
                                else if(type!=0)
                                {
                                    s[a]='G';
                                    s[j]='B';
                                    cost2 =cost2+(pow(abs(a-j),type));
                                    a=-1;
                                    break;
                                }
                            }
                        }
                        else
                        for(j=i+1;j<n;j=j+2)
                        {
                            if(s[j]=='B')
                            {
                                if(type==0&&a-j!=0)
                                {
                                    s[a]='B';
                                    s[j]='G';
                                    cost2++;
                                }
                                else if(type!=0)
                                {
                                    s[a]='B';
                                    s[j]='G';
                                    cost2 =cost2+(pow(abs(a-j),type));
                                    a=-1;
                                    break;
                                }
                            }
                        }
                    }
                    //cout<<"2cost"<<cost2<<endl;
                }
                cost= cost<cost2?cost:cost2;
                cout<<cost<<endl;
            }
            else
                cout<<"-1\n";
        }
    }
    return 0;
}
