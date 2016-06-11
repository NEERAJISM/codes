#include<stdio.h>
int main()
{
    int t,i,a[100];
    char s[100][50];

    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%s%d",&s[i],&a[i]);
    }

    for(i=0;i<t;i++)
    {
        printf("%d",s[i],a[i]);
    }


}
