#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
   long long int n,type,t,next,cost1,cost2,i,j,flag1,flag2;
    string s;
    char t1;
    cin>>t;

    while(t--)
    {

        cin>>type;

        cin>>s;
        n=s.size();
        cost1=0;
        cost2=0;
        flag1=0;
        flag2=0;

        for(i=0;i<n;i++)                //loop for BGBGBG
        {
            if((i%2==0&&s[i]=='G')||(i%2==1&&s[i]=='B'))
            {
                flag1=1;
                //cout<<"1 "<<i<<endl;
                if(s[i]=='G')
                {
                    for(j=i+1;j<n;j+=2)
                    {
                        if(s[j]=='B')
                        {
                            t1=s[i];
                            s[i]=s[j];
                            s[j]=t1;
                            flag1=0;
                            cost1=cost1+pow(abs(i-j),type);
                        }
                    }
                }
                else
                {
                    for(j=i+1;j<n;j+=2)
                    {
                        if(s[j]=='G')
                        {
                            t1=s[i];
                            s[i]=s[j];
                            s[j]=t1;
                            flag1=0;
                            cost1=cost1+pow(abs(i-j),type);
                        }
                    }
                }
            }
            if(flag1==1)
                break;
        }

        for(i=0;i<n;i++)                //loop for GBGBGB
        {
            if((i%2==0&&s[i]=='B')||(i%2==1&&s[i]=='G'))
            {
                flag2=1;
                //cout<<"2 "<<i<<endl;
                if(s[i]=='B')
                {
                    for(j=i+1;j<n;j+=2)
                    {
                        if(s[j]=='G')
                        {
                            t1=s[i];
                            s[i]=s[j];
                            s[j]=t1;
                            flag2=0;
                            cost2=cost2+pow(abs(i-j),type);
                        }
                    }
                }
                else
                {
                    for(j=i+1;j<n;j+=2)
                    {
                        if(s[j]=='B')
                        {
                            t1=s[i];
                            s[i]=s[j];
                            s[j]=t1;
                            flag2=0;
                            cost2=cost2+pow(abs(i-j),type);
                        }
                    }
                }
            }
            if(flag2==1)
                break;
        }

        if(flag1==1&&flag2==1)
            cout<<"-1"<<endl;
        else if(flag1==1)
            cout<<cost2<<endl;
        else if(flag2==1)
            cout<<cost1<<endl;
        else
        {
            if(cost2<cost1)
                cost1=cost2;

            cout<<cost1<<endl;;
        }
    }
return 0;
}
