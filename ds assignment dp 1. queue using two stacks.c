#include<stdio.h>
int stack1[100],x=0,stack2[100],top1=0,top2=0,d;
void enqueue();
void dequeue();
int main()
{
    char c[1];
    while(x!=1)
    {

        printf("enter \n 'i' to insert \n 'd' to delete \n 'e' to exit\n");
        scanf("%s",&c[0]);
        switch(c[0])
        {
            case('i'):
            enqueue();
            break;

            case('d'):
            dequeue();
            break;

            case('e'):
            x=1;
            break;
        }

        if(x==1)
        {
            break;
        }
    }

    return 0;
}

void enqueue()
{   printf("you are about to insert");
    if(top2!=0)
    {
        while(top2!=0)
        {
            top1=top1+1;
            stack1[top1]=stack2[top2];
            top2--;
        }
    }
    else
    {
        if(top1==99)
        printf("queue overflow");
        else
        {
            top1=top1+1;
            scanf("%d",&d);
            stack1[top1]=d;
        }
    }
}

void dequeue()
{
    if(top1!=0)
    {
        while(top1!=0)
        {
            top2=top2+1;
            stack2[top2]=stack1[top1];
            top1--;
        }
    }

    else if(top2==0)
    printf("queue underflow");

    else
    top2--;
}

