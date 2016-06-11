#include<string.h>
#include<stdio.h>
int main()
{
    int i=0,len,t,bal=0,maxbal=0,j;
    char a[100000],b[100000];

    scanf("%d",&t);
     for(j=0;j<t;j++)
    {

        scanf("%s",a);
        i=0;
        bal=0;
        maxbal=0;
        while(a[i]!='\0')
        {
            if(a[i]=='(')
                bal++;
            else
                bal--;
            maxbal =(maxbal>bal?maxbal:bal);
            i++;
        }

        for(i=0;i<2*maxbal;i++)
        {
            if(i<maxbal)
                b[i]='(';
            else
                b[i]=')';
        }
            printf("%s",b);
            if(j<t-1)
                printf("\n");
    }
return 0;
}

