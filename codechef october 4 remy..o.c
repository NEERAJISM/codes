#include<stdio.h>
#define mod 1000000009
int main()
{
    int t,n,m,y,save,j=0,op=1,a[100000],temp,k,i;
    char s[100000],x[1];

    scanf("%d",&t);
    while(t-->0)
    {
        op=1;
        j=0;
        scanf("%d%d",&n,&m);
        while(j<m)
        {
            scanf("%s%d",&x[0],&y);
            s[y]=x[0];
            a[j]=y;
            j++;
        }
        for(j=0;j<m;j++)
        {
            for(k=0;k<j;k++)
            {
                if(a[k]>a[j])
                {    temp=a[k];
                    a[k]=a[j];
                    a[j]=temp;
                }
            }
        }

        j=0;
        save=a[0];
        j++;
        while(j<m)
        {
            if(s[save]!=s[a[j]])
                {
                    temp=a[j]-save-1;
                    op=(op*temp*2)%mod;
                    save=a[j];
                }
            j++;
        }

        printf("%d\n",op);

    }
return 0;
}
