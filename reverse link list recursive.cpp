#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

void reverselist(struct node* start,struct node* prev,struct node* current)
{
    if(current->link ==NULL)
    {
        start = current;
        current->link = prev;
        return;
    }

    struct node* next = current->link;
    current->link = prev;
    reverselist(start,current,next);
}

int main()
{
    int n,i,d;
    scanf("%d",&n);

    struct node* start = NULL;
    struct node* ptr;

    for(i=0;i<n;i++)
    {
        scanf("%d",&d);

        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp ->data =d;
        temp->link = NULL;

        if(start == NULL)
        {
            start = temp;
        }
        else
        {
            temp ->link = start;
            start = temp;
        }
    }

    struct node* current = start;

    reverselist(start,NULL,current);

    ptr = start;

    while(ptr!= NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }

return 0;
}
