#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;
int main()
{
    int t,n,x,sum,mini,temp,i;
    scanf("%d",&t);

    while(t--)
    {
        sum = 0;
        scanf("%d%d",&n,&x);

        mini = INT_MAX;
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp <mini)
                mini = temp;

            sum+=temp;
        }

        if(sum<x)
            printf("-1\n");
        else if(sum%x==0)
            printf("%d\n",sum/x);
        else
        {
            int extra = sum - x*(sum/x);
            //cout<<mini<<"**"<<extra<<endl;
            if(mini <= extra)
                printf("-1\n");
            else
                printf("%d\n",sum/x);
        }
    }
return 0;
}
