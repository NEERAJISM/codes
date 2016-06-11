#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* link;
};

int main()
{
    int n,i,d;

    scanf("%d",&n);

    node* start = NULL;
    node* ptr;

    for(i=0;i<n;i++)
    {
        scanf("%d",&d);

        node* temp = (node*)malloc(sizeof(node));
        temp->data = d;
        temp->link =NULL;

        if(start == NULL)
        {
            start = temp;
        }
        else
        {
            temp->link=start;
            start = temp;
        }
    }

    ptr  =start;

    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }

    node *slow_ptr = start;
    node *fast_ptr = start;
    node *start2,*par;

    if(start != NULL && start->link != NULL)
    {
        while(fast_ptr != NULL && fast_ptr->link!=NULL)
        {
            par = slow_ptr;
            slow_ptr = slow_ptr->link;
            fast_ptr = fast_ptr->link->link;
        }

        if(fast_ptr == NULL) //even
        {
            cout<<"even"<<endl;
            par->link = NULL;
            start2= slow_ptr;
        }
        else //odd
        {
            cout<<"odd"<<endl;
            par->link = NULL;
            start2 = slow_ptr->link;
        }

        ptr = start2;
        node *prev = NULL , *current=start2,*next;
        node* ptr2 = start2;

        while(current!=NULL)
        {
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }

        start2= prev;

        ptr2 = start2;
        ptr = start;

        int flag = 0;

        while(ptr!= NULL)
        {
            if(ptr->data != ptr2->data)
            {
                flag=1;
                break;
            }

            ptr = ptr->link;
            ptr2 = ptr2->link;
        }

        if(flag==0)
            cout<<"palindrome\n";
        else
            cout<<"not a palindrome\n";
    }
    else
    {
        if(start==NULL)
            cout<<"null string\n";
        else
            cout<<"palindrome";
    }
return 0;
}
