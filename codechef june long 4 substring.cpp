#include<iostream>
#include<iterator>
#include<map>
#include<cstdio>

#define mod 1000000007
using namespace std;

long long int triangle[5001][5001];

void makeTriangle()
{
    int i, j;
    // initialize the first row
    triangle[0][0] = 1; // C(0, 0) = 1

    for(i = 1; i <= 5000; i++)
    {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            triangle[i][j] = (triangle[i - 1][j - 1] + triangle[i - 1][j])%mod;
        }
    }
}
int main()
{
    makeTriangle();
    int t;
    int n,i,j,k,sizey,q;
    long long int county;
    char s[5001];

    map<string, int> counters;
    scanf("%d",&t);

    while(t--)
    {
        counters.clear();
        scanf("%d%d",&n,&q);
        scanf("%s",&s);

        for(int size1 = 1;size1 <=n;size1++)
            for(int j=0;j+size1<=n;j++)
            {
                string sub(s+j,s+j+size1);
                ++counters[sub];
            }

        for(i=1 ; i<=q ; i++)
        {
            county = 0;
            scanf("%d",&k);
            if(k>n)
                cout<<"0\n";
            else
            {   map<string, int>::iterator it = counters.begin();
                for (it;it != counters.end(); ++it)
                {   //cout<<it->first<<endl;
                    int num = (*it).second;
                    if(num >= k)
                    {
                        //cout<<"***"<<num<<endl;
                        if(num==k)
                            county++;
                        else
                            county = (county + triangle[num][k])%mod;
                    }
                    //cout<<"county "<<county<<endl;
                }
                printf("%lld\n",county);
            }

        }
    }
return 0;
}
