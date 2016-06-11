#include<math.h>
#include<stdio.h>
int main()
{
    int t,n,i,x,y,x1,y1,a[1000][2],j;
    double ans,ans1;
    scanf("%d",&t);
    while(t-->0)
    {
        ans= 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<2;j++)
               scanf("%d",&a[i][j]);
        }
        for(i=0;i<n;i++)
        {
            x=a[i][0];
            y=a[i][1];

            for(j=i+1;j<n;j++)
            {
                x1=a[j][0]-x;
                y1=a[j][1]-y;
                ans1= sqrt((x1*x1)+(y1*y1));
                ans = (ans>ans1?ans:ans1);
            }
        }
        printf("%lf\n",ans);
    }
return 0;
}
