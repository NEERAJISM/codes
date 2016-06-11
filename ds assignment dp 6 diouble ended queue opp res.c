//output restricted queue
#include<stdio.h>
void enqueue();
void dequeue();

int q[100],n=100,r=0,f=0,x,i,item   ;
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
    printf("enter \n 'f' to insert from front \n enter 'b' to insert from back\n");
    char c[1];
    scanf("%s",&c[0]);

    if(c=='f')
    {
        if(r==99)
        printf("queue overflow");

        else
            r=r+1;
        scanf("%d",&item);

        q[r]=item;
    }
    else
    {
        if(r==99&&f==0)
        printf("queue overflow");

        else
        {
            while(r>0)
            {
                q[r+1]=q[r];
                r--;
            }
        scanf("%d",&item);
        q[r]=item;

        }
    }
}

void dequeue()
{
    if(f==0||r==0)
    {
        printf("queue underflow\n");
        return;
    }

    else if(r==f)
    {
        r=0;
        f=0;
    }

    else
        f=f+1;
 }






