#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

struct node* start=NULL;
struct node* ptr;
struct node* new1;
void insert(int a)
{

    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=a;
    new1->link=NULL;
    int t;
    cout<<"enter 1 to insert at the beginning \n2 to insert at the end\n";
    cin>>t;

    if(t==1)
    {
        if(start==NULL)
            start=new1;
        else
            new1->link=start;
            start=new1;
    }
    else
    {
        if(start==NULL)
            start=new1;
        else
        {
            ptr= start;

            while(ptr->link!=NULL)
                ptr=ptr->link;

            ptr->link=new1;
        }
    }
}

void display()
{
    ptr=start;

    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
}

void delete1(int d)
{
    ptr= start;

    if(ptr->data==d)
    {
        start = ptr->link;
        return ;
    }

    while(ptr->link->data!=d&&ptr->link!=NULL)
        ptr=ptr->link;

    if(ptr->link==NULL)
        cout<<"item not found\n";
    else
        ptr->link=ptr->link->link;
}

int main()
{
    int t,d;
    while(1)
    {
        cout<<"enter\n1 to insert in a link list\n2 to delete in a link list\n3 to print the link list\n4 to exit\n";
        cin>>t;

        if(t==1)
        {
            cout<<"enter the data to be inserted ";
            cin>>d;
            insert(d);
        }
        else if(t==2)
        {
            cout<<"enter the data to be deleted\n";
            cin>>d;
            delete1(d);
        }
        else if(t==3)
            display();
        else if(t==4)
            break;
    }
return 0;
}
