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
    struct node* ptr;

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

    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }

    cout<<endl;

    //reverse

    struct node* current = start;
    struct node* prev = NULL;
    struct node* next;

    while(current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    start = prev;

    ptr = start;

    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }
return 0;
}
