#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

int main()
{
    int n,i,d;

    struct node* start= NULL;
    struct node *ptr,*next,*temp;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&d);

        struct node* temp =(struct node*)malloc(sizeof(struct node));
        temp->data = d;
        temp->link = NULL;

        if(start ==NULL)
            start =temp;
        else
        {
            temp ->link = start;
            start = temp;
        }
    }

    ptr = start;

    while(ptr->link->link!=NULL)
    {
        ptr = ptr->link;
    }
    struct node* nxt = ptr->link;
    ptr->link = NULL;

    nxt->link = start;
    start = nxt;

    ptr =start;

    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }
return 0;
}
