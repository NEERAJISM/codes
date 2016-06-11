#include <bits/stdc++.h>
using namespace std;
int a[1002][1002];
int main()
{
    int t,i,j,count1,x,y,flag1,flag2,flag3,flag4,k;
    long long int total,n;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld%d",&n,&k);

        if(k==1||k==0)
        {
            total =n*n;
            if(k==0)
                printf("%lld\n",total);
            else
            {
                scanf("%d%d",&x,&y);
                long long int county1 = 1;

                i=1;
                while(x+i<=n && y+i<=n)
                {
                    county1++;
                    i++;
                }

                i=1;
                while(x-i>0 && y-i>0)
                {
                    county1++;
                    i++;
                }

                i=1;
                while(x-i>0 && y+i<=n)
                {
                    county1++;
                    i++;
                }

                i=1;
                while(x+i<=n && y-i>0)
                {
                    county1++;
                    i++;
                }

                printf("%lld\n",total - county1);
            }
        }
        else
        {
            count1 = 0;
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    a[i][j] =0;

            for(int tt =0;tt<k;tt++)
            {
                scanf("%d%d",&x,&y);

                a[x][y] =1;

                flag1= 0;
                flag2 =0;
                flag3 =0;
                flag4 =0;

                i=1;

                while(1)
                {
                    if(flag1 ==1 &&flag2 ==1 &&flag3 ==1 &&flag4 ==1 )
                        break;

                    if( flag1 !=1 && x+i<=n && y+i<=n )
                        a[x+i][y+i] = 1;
                    else
                        flag1=1;

                    if(flag2 !=1 &&x-i>0 && y-i>0)
                        a[x-i][y-i] = 1;
                    else
                        flag2=1;

                    if(flag3 !=1 &&x-i>0 && y+i<=n)
                        a[x-i][y+i] = 1;
                    else
                        flag3=1;

                    if(flag4 !=1 &&x+i<=n && y-i>0)
                        a[x+i][y-i] = 1;
                    else
                        flag4=1;

                    i++;
                }
            }


            int county =0;

            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(a[i][j] ==0)
                        county++;

            printf("%d\n",county);
        }
    }
return 0;
}
