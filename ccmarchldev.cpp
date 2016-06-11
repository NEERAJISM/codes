#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
string s;
int main()
{
   unsigned long long int n,type,t,next,cost1,cost2,i,j,flag1,flag2;

    char t1;
    scanf("%lld",&t);
    while(t-->0)
    {
        scanf("%lld",&type);
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
                //cout<<"mismatch "<<s[i]<<endl;
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
                            cost1=cost1+pow(j-i,type);
                        }
                    }
                }
                else
                {
                    for(j=i+1;j<n;j+=2)
                    {
                        if(s[j]=='G')
                        {
                  //          cout<<"2 "<<j<<endl;
                            t1=s[i];
                            s[i]=s[j];
                            s[j]=t1;
                            flag1=0;
                            cost1=cost1+pow(j-i,type);
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
                //cout<<"mismatch"<<s[i]<<endl;
                if(s[i]=='B')
                {
                    for(j=i+1;j<n;j+=2)
                    {

                        if(s[j]=='G')
                        {
                           // cout<<"2 "<<j<<endl;
                            t1=s[i];
                            s[i]=s[j];
                            s[j]=t1;
                            flag2=0;
                            cost2=cost2+pow(j-i,type);
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
                            cost2=cost2+pow(j-i,type);
                        }
                    }
                }
            }
            if(flag2==1)
                break;
        }

        if(flag1==1&&flag2==1)
            printf("-1\n");
        else if(flag1==1)
        {
            printf("%lld\n",cost2);
            //cout<<"flag=1 \n";
        }
        else if(flag2==1)
        {
            printf("%lld\n",cost1);
            //cout<<"flag=2 \n";
        }
        else
        {
            if(cost2<cost1)
                cost1=cost2;

            printf("%lld\n",cost1);
        }
    }
return 0;
}
