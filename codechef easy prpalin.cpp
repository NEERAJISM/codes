#include <iostream>
#include <cstdio>
using namespace std;
int a[1010000],i,j,n,i1;

int palindrome(int t)
{
    int b[9],k=0,r,flag=1;
    while(t!=0)
    {
        r= t%10;
        b[k] =r;
        k++;
        t=t/10;
    }

    for(i1=0;i1<k/2;i1++)
    {
        if(b[i1] != b[k-1-i1])
        {
            flag =0;
            break;
        }
    }

    //cout<<flag<<endl;
    return flag;
}

int main()
{
    a[1] = 1;
    for(i=4;i<1010000;i+=2)
        a[i] = 1;

    for(i=3;i<=1005;i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<1010000;j+=i*2)
                a[j]=1;
        }
    }

    scanf("%d",&n);
    int add;

    if(palindrome(n))
    {
        printf("%d\n",n);
    }
    else
    {
        if(n%2==0)
            add = 1;
        else
            add = 2;

        if(n==1)
            add--;

        for(i=n+add;i<=1010000;i+=2)
        {
            if(a[i]==0)
            {
                if(palindrome(i))
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
return 0;
}
