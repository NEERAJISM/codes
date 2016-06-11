#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*  next;
}node;

struct node *p;
struct node *q;
struct node *start=NULL;
struct node *ptr;
void getnode(int);
void insert(struct node* );

int main()
{
    int x,flag=5;
    char c[1];

    scanf("%d",&x);
    while(flag!=0)
    {
        printf("enter \n 'i' to insert \n 'd' to delete \n 'c' to count \n 'e' to exit");
        scanf("%s",&c[0]);

        if(c[0]=='i')
        {
            getnode(x);
            insert(q);
        }
    }



return 0;
}

void getnode(int data)
{

    p=(struct node*)malloc(sizeof(struct node));

    p->data=data;
    p->next=NULL;

}

void insert(struct node* p )
{
    if(start==NULL)
    {
        start=p;
    }
    else
    {
        printf("enter \n 's' to insert at start \n 'e' to insert at end \n 'm' to insert in mid of link list \n");
        char z[1];
        scanf("%s",&z[0]);

        if(z[0]=='s')
        {
            p->next=start;
            start=p;
        }

        else if(z[0]=='e')
        {
            ptr=start;
            while(ptr!=NULL)
            {
                ptr=ptr->next;
            }

            ptr=p;
        }

    }
}
