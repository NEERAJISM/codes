#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,k,i,m,b=0,j,a[100005],lengthsum=0,length,first;
    scanf("%d%d",&n,&k);

    for(i=0;i<k;i++)
    {
        scanf("%d",&m);

        for(j=0 ; j<m ; j++)
            scanf("%d",&a[j]);

        for(j=0;j<m-1;j++)
        {
            length = 1;
            first = a[j];

            while(a[j+1]-a[j]==1 && j+1<m)
            {
                length++;
                j++;
            }

            //cout<<length<<"/*/\n";

            if(first!=1)
                lengthsum+=(length-1)*2;

            if(a[j+1]-a[j]!=1&& j+1<m)
                b++;
        }
    }
    //cout<<b<<"\\"<<endl;
    printf("%d",k+2*b-1+lengthsum);
return 0;
}
