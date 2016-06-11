#include <stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node* link;
};

node* start = NULL;
void push(int value)
{


    node* temp = (node*)malloc(sizeof(node));
    temp->data =value;
    temp->link = NULL;

    if(start == NULL)
        start = temp;
    else
    {
        temp->link = start;
        start = temp;
    }
}


void  reverselist()
{
    node* ptr = start;

    while(ptr->link!=NULL)
    {
       node* next = ptr->link;
       ptr->link = next->link;
       next->link =start;
       start =next;
    }
}

int main()
{
    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        push(x);
    }

    cout<<"print : ";

    node* ptr = start;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }

    cout<<endl<<"\nreverseof th list :";

    reverselist();

    ptr =start;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }
return 0;
}
