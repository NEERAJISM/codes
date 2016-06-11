//stack implementation using queue
#include<stdio.h>
int q1[101],q2[101],*ptr,f1,r1,f2,r2,item;
void push();
void push2(int);
void pop();
void pop();
int main()
{  int  f1=0;
   int  f2=0;
   int  r1=0;
   int  r2=0;
   char c[1];

        while(1)
        {
            printf("enter the operation to be performed\n i to insert\n d to delete\n e to exit\n");
            scanf("%s",&c);
            switch(c[0])                       //switch case
            {
                case('i'):
                push();
                break;

                case('d'):
                while(f1!=0&&r1!=0)
                pop();
                break;

                case('e'):
                break;
            }
        if(c[0]=='e')
        break;

        }
return 0;
}

void push()              //circular queue insertion
{
    printf("you are about to insert");
    if(r1==0&&f1==0)
    {
        r1=1;
        f1=1;
    }
    else if(f1==1&&r1==100||r1+1==f1)
    printf("stack overflow");
    else if(r1==100)
    r1=1;
    else
    r1=r1+1;

    scanf("%d",&q1[r1]);
}

void pop()              //circular queue deletion
{
    int item=q1[f1];

    if(f1==0)                                       //deletion from q1 and insertion ion q2
    printf("stack underflow");
    else if( f1==r1)
    {
        f1=0;
        r1=0;
    }
    else if(f1==100)
    f1=1;
    else
    f1=f1+1;

    push2(item);
}

void push2(int x)
{
    if(r2==0&&f2==0)
    {
        r2=1;
        f2=1;                               //insert5ion in q2
    }
    else if(f2==1&&r2==100||r2+1==f2)
    printf("stack overflow");
    else if(r2==100)
    r2=1;
    else
    r2=r2+1;

    q2[r2]=item;

    pop2();
}


void pop2()
{
    int item=q2[f2];

    if(f2==0)                                       //deletion from q1 and insertion ion q2
    printf("stack underflow");
    else if( f2==r2)
    {
        f2=0;
        r2=0;
    }
    else if(f2==100)
    f2=1;
    else
    f2=f2+1;

 printf("item deleted is %d\n",item);

}
