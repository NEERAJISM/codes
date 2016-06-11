//input restricted queue
#include<stdio.h>
void enqueue();
void dequeue();

int q[100],n=100,r,f,x,i,item   ;
int main()
{
    char c[1];
    while(x!=1)
    {

        printf("enter\n 'i' to insesrt\n 'd' to delete\n 'e' to exit\n");
        scanf("%s",&c);
        switch(c[0])
        {
            case('i'):
            {
                enqueue();
                break;
            }

            case('d'):
            {
                dequeue();
                break;
            }

            case('e'):
            {
                x=1;
                break;
            }

        }
    }

    for(i=1;i<r;i++)
    printf("%d ",q[i]);

    return 0;
}

void enqueue()
{
    if(f==0&r==0)
    {
        f=1;
        r=1;
    }
    else if(f==1&&r==99)
    {
        printf("queue overflow\n");
    }
    else
        r=r+1;

    printf("please enter the item to be inserted\n");
    scanf("%d",&item);
    q[r]=item;
}

void dequeue()
{
    if(f==0||r==0)
    {
        printf("stack underflow\n");
        return;
    }
    printf("you are about to delete \n enter 'f' to delete from front \n 'b' to delete from back\n");
    char z[1];
    scanf("%s",&z);
    if(z[0]=='b')
    {
        if(r==f)
        {
            r=0;
            f=0;
        }
        else if(f==0||r==0)
        {
            printf("queue underflow\n");
        }
        else
            f=f+1;
    }
    else
    {
        if(r==f)
        {
            r=0;
            f=0;
        }
        else if(f==0||r==0)
        {
            printf("queue underflow\n");
        }
        else
            r=r-1;
    }
}
