#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,n,la,lb,flag;
    char a[10000],b[100000];
    char *ptr;

    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%s",&a);
        scanf("%s",&b);
        ;
        i=0;
        flag=0;
        while(a[i]!='\0'&&flag==0)
        {
            if(strchr(b,a[i])!=NULL)
                flag=1;

            i++;
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }

return 0;
}
