#include<stdio.h>
int main()
{
    int t,del;
    char a[100000];
    scanf("%d",&t);
    while(t--)
    {
        del=0;
        scanf("%s",a);
        int i=0;
        while(a[i]!='\0')
        {
            if(a[i]==a[i+1])
                del++;
            i++;
        }
        printf("%d\n",del);
    }
return 0;
}


