#include <iostream>
#include <cstdio>
#include <cmath>
long double a,sum,s1,sall,op;
using namespace std;
int main()
{
    int i,j,m,n,t,flag,flag1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        sall = 0;
        s1=0;
        for(i=0;i<n;i++)
        {
            flag = -1;
            sum = 0;
            flag1=0;
            for(j=0;j<m;j++)
            {
                a=0;
                cin>>a;

                if(a!=1)
                    flag1 = 1;

                if(a==0)
                {
                    sum = 0;
                    flag =0;
                }
                else
                {
                    sum=sum+log10(a);
                    //cout<<"sum at each step "<<sum<<endl;
                }
            }

            if(flag1==0)
            {
                if(i==0)
                    s1 =1;
                sall = 1;
            }
            else
            {
                if(flag == 0)
                {
                    sall += 0;
                    if(i==0)
                        s1 = 0;
                }
                else
                {
                    if(i==0)
                        s1 = pow(10,sum);
                    sall = sall + pow(10,sum);
                }
            }
        }
        s1 = (s1*100000000)/(sall*100000000);
        cout<<s1<<endl;
    }
    return 0;
}
/*
2
2 3
0.0022 0.975 0.22
0.9978 0.025 0.78*/
