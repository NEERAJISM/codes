#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
    struct node* arbit;

};

struct node* mergesort(struct node* a,struct node *b)
{
    struct node* result;

    if(a == NULL)
        return b;
    else if(b== NULL)
        return a;
    cout<<a->data<<" ** "<<b->data<<endl;
    if(a->data <= b->data)
    {
        result  = a;
        result ->arbit = mergesort(a->arbit,b);
    }
    else
    {
        result  = b;
        result ->arbit = mergesort(a,b->arbit);
    }

return result;
}


void findmid(struct node* src,struct node **a,struct node **b)
{
    if(src == NULL || src->arbit == NULL)
    {
        *a = src;
        *b = NULL;
        return ;
    }

    //cout<<"finding mid2\n";
    cout<<"src "<<src->data<<endl;
    struct node *fptr = src->arbit,*sptr = src;

    while(fptr != NULL && fptr->arbit != NULL)
    {
        fptr = fptr->arbit->arbit;
        sptr = sptr->arbit;
    }

    cout<<"sptr : "<<sptr->data<<endl;

    *a = src;
    *b = sptr->arbit;
    sptr->arbit = NULL;
}

void mergelist(struct node **start)
{
    struct node *head = *start ,*a,*b;

    if(head == NULL || head->arbit == NULL)
        return;

    findmid(head,&a,&b);

    mergelist(&a);
    cout<<"now for b\n";
    mergelist(&b);

    *start  = mergesort(a,b);
}

int main()
{
    int n,i,d,x1,y1;
    scanf("%d",&n);
    struct node *start= NULL,*ptr;


    for(i = 0;i<n;i++)
    {
        scanf("%d",&x1);

        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data  =x1;
        temp->arbit = NULL;
        temp->link =NULL;

        if(start == NULL)
            start = temp;
        else
        {
            temp ->link = start;
            start = temp;
        }
    }

    ptr= start;

    while( ptr!= NULL)
    {
        ptr->arbit = ptr->link;
        ptr = ptr->link;
    }

    ptr= start;

    while( ptr!= NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->arbit;
    }
    cout<<endl;

    mergelist(&start);

    ptr= start;
    cout<<"the new modified array with next big number can be given as : ";
    while(ptr!= NULL)
    {
        cout<<ptr->data<<" ";
        ptr =ptr->link;
    }

return 0;
}
