#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};

    struct node* start = NULL;
    struct node* ptr;
    struct node* save;

void insert(int d)
{
    struct node* new1 =(struct node*)malloc(sizeof(struct node));
    new1->link = NULL;
    new1->data = d;

    if(start == NULL)
    {
        start = new1;
        printf("ptr %d\n",start->data);
    }
    else
    {
        ptr = start;

        while(ptr->link!=NULL)
        {
            ptr= ptr->link;
        }
        ptr->link= new1;
        printf("ptr %d\n",ptr->data);
    }
}

void view()
{
    ptr = start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
    }
}

int main()
{
    int i,item;


    for(i=0;i<5;i++)
    {

        printf("enter the number to be inserted");
        scanf("%d",&item);

        insert(item);

    }

    view();
return 0;
}

