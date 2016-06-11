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

    while(ptr->link!=NULL)
    {
        cout<<"**\n";
        ptr = ptr->link;
    }
    ptr->link = start;

    struct node* ptr2= start;
    ptr= start;

    int flag = 0;
    while(ptr!= NULL &&ptr2!=NULL && ptr2->link!=NULL)
    {
        ptr = ptr->link;
        ptr2 = ptr2->link->link;

        if(ptr == ptr2)
        {
            flag = 1;
            break;
        }
    }

    if(flag==1)
        cout<<"cycle"<<endl;
    else
        cout<<"no cycle"<<endl;
return 0;
}
