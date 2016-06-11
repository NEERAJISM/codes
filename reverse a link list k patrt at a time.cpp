#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *link;
};

struct node* reversek(struct node *head ,int  k)
{
    struct node *current = head, *next ,*prev = NULL;
    int count1 = 0;
    while(current != NULL && count1<k)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current =next;
        count1++;
    }

    if(current!=NULL)
    {
        head->link = reversek(next,k);
    }
    return prev;
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

    struct node *ptr =start;

    while(ptr!= NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }
    cout<<endl;
int k;
    scanf("%d",&k);
    start = reversek(start,k);

    ptr =start;

    while(ptr!= NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }

return 0;
}
