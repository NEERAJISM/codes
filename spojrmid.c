#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* link;
};
struct node* start=NULL;
struct node* ptr=NULL;
struct node* save=NULL;
int n;

void add(int d1)
{
    struct node *new =(struct node*)malloc(sizeof(struct node));
    new->data = d1;
    new->link = start;
    start =new;
}

void median()
{
    int med;
    ptr=start;
    med=n/2+1;

    if(med==1)
    {
        printf("%d\n",start->data);
        start=NULL;
    }
    else
    {
        while(med>1)
        {
            save=ptr;
            ptr=ptr->link;
            med--;
        }
        printf("%d\n",ptr->data);
        save->link = ptr->link;
    }
    n--;
}

int main()
{
    int d;
    while(1)
    {
        n=0;
        start=NULL;
        while(1)
        {
            scanf("%d",&d);
            if(d==0)
            {
                printf("\n");
                break;
            }
            else if(d==-1)
                median();
            else
            {
                add(d);
                n++;
            }
        }
    }
    return 0;
}
