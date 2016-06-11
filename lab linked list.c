#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
};

struct node* start;
struct node* ptr;

void insert(int x);
void delete();
int main()
{
    int flag=0,d;
    char c[1];
    while(flag==0)
    {
        printf("enter \n 'i' to insert \n 'd' to delete \n 'v' to display \n 'e' to exit\n");
        scanf("%s",&c[0]);

        if(c[0]=='i')
        {
            printf("enter the item to be inserted\n");
            scanf("%d",&d);
            insert(d);
        }
        else if(c[0]=='v')
        {
            ptr=start;
            while(ptr!=NULL)
            {
                printf("%d\n",ptr->data);
                ptr=ptr->link;
            }
        }
        else if(c[0]=='d')
            delete();

        else if(c[0]=='e')
            flag=1;
    }
return 0;
}


void insert(int x)
{
    int d,pivot;
    char y;
    struct node* new =(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    printf("%d**",new->data);

    printf("enter \n 1 to insert in begining \n 2 to insert at end \n 3 to insert in between\n");

    scanf("%d",&d);
    if(d==1)
    {
        if(start==NULL)
            start=new;

        else
        {
            new->link=start;
            start=new;
        }
    }
    else if(d==2)
    {
        ptr=start;
        while(ptr!=NULL)
            ptr=ptr->link;

        ptr=new;
    }
    else if(d==3)
    {
        printf("enter the number which is pivot");
        scanf("%d",&pivot);

        printf("enter \n 'b' to enter before the pivot \n 'a' to enter after the pivot");
        scanf("%c",&y);

        if(y=='b')
        {
            ptr=start;

            while(ptr->link->data!=pivot)
                ptr=ptr->link;

            new->link=ptr->link;
            ptr->link=new;
        }
        else
        {
            ptr=start;

            while(ptr->data!=pivot)
                ptr=ptr->link;

            new->link=ptr->link;
            ptr->link=new;
        }
    }
}


void delete()
{
    int item;
    struct node* temp;
    printf("enter the item you want to delete");
    scanf("%d",&item);

    ptr=start;

    while(ptr->data!=item&&ptr!=NULL)
        ptr=ptr->link;

    if(ptr==NULL)
        printf("the item does not exist in the linked list");

    else if(ptr==start)
        start=ptr->link;

    else
    {
        temp=ptr->link;
        ptr->link=NULL;
        ptr=temp;
    }
}
