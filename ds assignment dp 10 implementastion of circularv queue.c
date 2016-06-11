//implementation of circular queue
#include<stdio.h>
int f1,r1,q1[101];

void ins();
void del();
int main()
{  int  f1=0;
   int  r1=0;
   int  x=0;
   char c[1];

        while(10)
        {
            printf("enter the operation to be performed\n i to insert\n d to delete\n e to exit\n");

            scanf("%s",&c);
            switch(c[0])                       //switch case
            {
                case('i'):
                ins();
                break;

                case('d'):
                del();
                break;

                case('e'):
                break;
            }
            if(c[0]=='e')
            break;

        }
return 0;
}

void ins()              //circular queue insertion
{   printf("please insert the value\n");

    if(r1==0&&f1==0)
    {
        r1=1;
        f1=1;
    }
    else if(f1==1&&r1==100||r1+1==f1)
    printf("stack overflow\n");
    else if(r1==100)
    r1=1;
    else
    r1=r1+1;

    scanf("%d",&q1[r1]);
}

void del()              //circular queue deletion
{
    printf("you are about to delete\n");
    int item=q1[f1];

    if(f1==0)                                       //deletion from q1
    printf("stack underflow\n");
    else if( f1==r1)
    {
        f1=0;
        r1=0;
    }
    else if(f1==100)
    f1=1;
    else
    f1=f1+1;

 }

