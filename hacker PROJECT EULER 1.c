#include<stdio.h>
int main()
{
    long int n,sum,t,n3,n5,n15;
    scanf("%ld",&t);
    while(t>0)
    {
        scanf("%ld",&n);
        n3=n-1;
        while(n3%3!=0&&n3>=3)
            n3--;

        if(n3<3)
            n3=0;

            sum=((3+n3)*(n3/3))/2;



        n5=n-1;
        while(n5%5!=0&&n5>=5)
            n5--;

        if(n5<5)
            n5=0;

            sum=sum+((5+n5)*(n5/5))/2;




        n15=n-1;
        while(n15%15!=0&&n15>=15)
            n15--;

        if(n15<15)
            n15=0;

            sum=sum-((15+n15)*(n15/15))/2;

        printf("%ld\n",sum);

        t--;
    }
return 0;
}
