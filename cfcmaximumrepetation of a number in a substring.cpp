#include <iostream>
#include <cstdio>
int t,i,n,j,a[100005],b[1000006][2],last[100005],n1=1,mini=1000000000,mini2,max1 =-1,distinct[100005],distinct2[100005][3],n2=1;

using namespace std;
int main()
{
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);


        if(b[a[i]][0]==0)
        {
            b[a[i]][1] = i;
            distinct[n1] =i;
            n1++;
        }
        b[a[i]][0]++;

        if(b[a[i]][0] > max1)
            max1 = b[a[i]][0];
    }

    for(i=1;i<=n1;i++)
    {
        if(b[a[distinct[i]]][0] == max1)
        {
            distinct2[n2][0] = distinct[i];

            for(j=n;j>0;j--)
            {
                if(a[j]==a[distinct[i]])
                {
                    distinct2[n2][1] = j;
                    distinct2[n2][2] = distinct2[n2][1] - distinct2[n2][0] +1;

                    if(distinct2[n2][2]<mini)
                    {
                        mini = distinct2[n2][2];
                        mini2 = n2;
                    }
                    break;
                }
            }
            n2++;
        }

    }
    printf("%d %d",distinct2[mini2][0],distinct2[mini2][1]);
return 0;
}
