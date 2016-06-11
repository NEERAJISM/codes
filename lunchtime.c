#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,i,j,a[26];
    char c[50];
    scanf("%d",&t);
    while(t-->0)
    {
        for(i=0;i<26;i++)
            a[i]=0;
        scanf("%s",&c);
        n=strlen(c);
        if(n%2!=0)
            printf("NO\n");
        else
        {
            for(i=0;i<n;i++)
                a[c[i]-97]++;
            j=0;

            for(i=0;i<26;i++)
                j=a[i]>j?a[i]:j;

            if(j==n/2)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
return 0;
}
