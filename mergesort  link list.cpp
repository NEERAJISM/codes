#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

void divide(struct node *src,struct node **a,struct node **b)
{
    if(src==NULL || src->link == NULL)
    {
        *a = src;
        *b = NULL;
        return;
    }

    struct node *fptr=src->link, *sptr = src;

    while(fptr !=NULL && fptr->link != NULL)
    {
        sptr = sptr->link;
        fptr = fptr->link->link;
    }

    cout<<"sptr : "<<sptr->data<<endl;

    *a = src;
    *b = sptr->link;
    sptr->link = NULL;
}

struct node* merged(struct node *a,struct node *b)
{
    struct node *result = NULL;

    if(a==NULL)
        return b;
    if(b==NULL)
        return a;

    if(a->data <= b->data)
    {
        result = a;
        result->link = merged(a->link,b);
    }
    else
    {
        result = b;
        result->link = merged(a,b->link);
    }
    return result;
}

void mergelist(struct node **start)
{
    struct node *head = *start;
    struct node *a,*b;

    if(head == NULL || head->link == NULL)
        return;

    divide(head,&a,&b);

    cout<<"sptr a : "<<a->data<<endl;
    cout<<"sptr b : "<<b->data<<endl;

    mergelist(&a);
    mergelist(&b);

    *start = merged(a,b);
}

int main()
{
    int n,i,d;
    scanf("%d",&n);
    struct node* start=NULL;

    for(i=0;i<n;i++)
    {
        scanf("%d",&d);
        struct node* temp = (struct node*)malloc(sizeof(node));
        temp->data = d;
        temp->link = NULL;

        if(start == NULL)
            start = temp;
        else
        {
            temp->link = start;
            start = temp;
        }
    }

    struct node *ptr = start;
    ptr= start;
    cout<<"the orignal link list : ";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }
    cout<<endl;

    mergelist(&start);

    ptr= start;

    cout<<"the sorted link list : ";

    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }

return 0;
}
