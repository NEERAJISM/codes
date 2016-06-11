#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int a[100000][2000];
int main()
{
    int t,n,e,i,j,f1,f2,b[100000],c[100000],count1;

    scanf("%d",&t);
    while(t--)
    {
        count1 = 0;
        scanf("%d%d",&n,&e);

        for(i=0;i<n;i++)
        {
            b[i]=0;
            c[i]=0;
        }

        for(i=0;i<e;i++)
        {
            scanf("%d%d",&f1,&f2);

            a[f1][c[f1]]=f2;
            a[f2][c[f2]]=f1;
            c[f1]++;
            c[f2]++;
        }

        for(i=0;i<n;i++)
        {
            if(b[i]==0)
            {
                count1++;
               /* b[i] = 1;

                if(c[i]>0)
                {
                    for(j=0;j<c[i];j++)
                    {
                        b[a[i][j]]=1;
                    }
                }*/

                queue<int> q;
                q.push(i);

                while(q.empty()==0)
                {
                    if(c[q.front()]>0)
                    {
                        for(j=0;j<c[q.front()];j++)
                        {
                            if(b[a[q.front()][j]]==0)
                            {
                                q.push(a[q.front()][j]);
                            }
                        }
                    }
                    b[q.front()] =1;
                    q.pop();
                }
            }
        }


        printf("%d\n",count1);
    }
    return 0;
}
