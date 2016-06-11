#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    long long int t,power[15],temp,pow10,n,m,i,j;
    long double probi[15],currentp,numerator,denominator;
    float ip;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        for(i=0;i<n;i++)
        {
            currentp = 1;
            pow10 = 0;
            for(j=0;j<m;j++)
            {
                scanf("%f",&ip);
                ip = ip*10000;
                pow10 += 4;

                //cout<<ip<<" ip"<<endl;
                currentp*=ip;

                if(currentp>10000)
                {
                    currentp/=10000;
                    pow10 -= 4;
                }
            }
            probi[i] = currentp;
            power[i] = pow10;

             //cout<<"probi[i]"<<probi[i]<<endl;
        }

        numerator = probi[0];
        denominator = 0;

        for(i=0;i<n;i++)
            denominator+=(probi[i]*pow(10,(power[0]-power[i])));

        //cout<<numerator<<" **  "<<denominator<<endl;
        if(abs(numerator)<0.000000001)
            printf("%.9Lf\n",(long double)0);
        else
            printf("%.9Lf\n",(numerator/denominator));
    }
return 0;
}
