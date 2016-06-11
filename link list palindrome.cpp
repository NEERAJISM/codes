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
    int n,i;
    int c;

    scanf("%d",&n);

    struct node* start = NULL;
    struct node* ptr;

    for(i=0;i<n;i++)
    {
        scanf("%d",&c);
        struct node* temp = (struct node*)malloc(sizeof(struct node));

        temp->data = c;
        temp->link = NULL;

        if(start == NULL)
        {
                        start = temp;
        }
        else
        {

            temp->link = start;
            start = temp;
        }
    }

    struct node *ptr1=start,*ptr2=start,*mid;

    while(ptr2!=NULL && ptr2->link!=NULL)
    {
        ptr1 = ptr1->link;
        ptr2 = ptr2->link->link;
    }
    mid= ptr1;


}
