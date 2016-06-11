#include<stdio.h>
#include<string.h>

int power(int x,int y)
{
    int t;
    if(y==0)
        return 1;
    else if(y%2>0)
        return (x*power(x,y-1));
    else
    {
        t=power(x,y/2);
        return t*t;
    }
}

int main()
{
    int  i,t,m,n,k,a,b1,c1,add,b[100000],d[100000],l,count;
    scanf("%d",&t);

    while(t-->0)
    {
        char c[10000];
        scanf("%d %s",&m,&c);
        n=strlen(c);

        k=0;
        add=0;
        for(i=0;i<n;i++)
        {
            if(c[i]=='*')
            {
                k++;
                add=0;
                if(c[i+1]=='*')
                {
                    b[k]=-2;
                    i++;
                }
                else
                    b[k]=-1;
                k++;
            }
            else
            {
                add=add*10+(c[i]-'0');
                b[k]=add;
            }
        }
        l=0;
        for(i=0;i<=k;i++)
        {
            if(b[i]==-2)
            {
                d[l-1]=power(b[l-1],b[i+1]);
                i++;
            }
            else
            {
                d[l]=b[i];
                l++;
            }
        }
        count=1;
        for(i=0;i<l;i++)
        {
            if(d[i]==-1)
            {
                count=count*(d[i-1]*d[i+1]);
                i++;
            }
        }
        printf("%d\n",count%m);

    }
return 0;
}
