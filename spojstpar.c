#include<stdio.h>
int a[1000];
int main()
{
    int n,t,i,j,chk,flag,save,top,stack[1000],k;
    t=1;
    while(1)
    {
        scanf("%d",&n);

        if(n==0)
            break;
        top=-1;
        flag=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        j=0;
        chk=0;
        for(i=0;i<n;i++)
        {
            chk++;
            flag=0;

            while(j<n)
            {
                if(a[j]==chk)
                {
                    j++;
                    break;
                }
                else if(a[j]!=chk&&top>=0)
                {
                    top++;
                    if(top>0)
                    {
                        if(a[j]>stack[top-1])
                        {
                            flag =1;
                            break;
                        }
                    }
                    stack[top]=a[j];
                    j++;
                }

            }

            if(flag==1)
                break;
        }
            if(flag==1)
                printf("no\n");
            else
            printf("yes\n");
    }
return 0;
}
