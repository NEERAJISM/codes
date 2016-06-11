#include<stdio.h>
int main()
{
int T,i,n,k,j,r;
scanf("%d",&T);
for(i=0;i<T;i++)
{r=0;
scanf("%d %d\n",&n,&k);
int a[60];
for(j=0;j<n;j++)
{scanf("%d\n",&a[j]);
if(a[j]%2==0)
    r=r+1;
}
}
if(r>=k)
printf("YES\n");
else if(r==n&&k==0)
    printf("NO");
else
printf("NO\n");
return 0;
}
