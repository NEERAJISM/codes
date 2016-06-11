#include<stdio.h>
long long int count;
void length(long long int x);
void strange(int y,long long int);
int main()
{
long long int l,r,i;
int t;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%lld%lld",&l,&r);
        i=l;
        count=0;

        while(i<=r)
        {
            length(i);
            i++;
        }
        printf("%lld\n",count);
    }
return 0;
}

void length(long long int x)
{
    long long int temp=x;
    int len=0;
    while(temp>=1)
    {
        temp=temp/10;
        len++;
    }
    strange(len,x);

}

void strange(int y,long long int z)
{
    if(y==1||y==0)
        count++;


    else
    {
        if(z%y==0)
        {
            z=z/y;
            length(z);
        }
    }
}




