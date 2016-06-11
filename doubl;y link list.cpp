#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

int main()
{
    int n,d;
    scanf("%d",&n);
    struct node *start=NULL,*ptr;
    while(n--)
    {
        printf("insert the data : ");
        scanf("%d",&d);


        struct  node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = d;
        temp->next = NULL;
        temp->prev = NULL;

        printf("enter the charectar to insert at 'b' , 'e' , 'a' : ");
        char c;
        scanf("%s",&c);

        if(c == 'b')
        {
            if(start == NULL)
                start = temp;
            else
            {
                temp->next  = start;
                start = temp;
                temp->next->prev = temp;
            }
        }
        else if(c=='e')
        {
            if(start == NULL)
                start == temp;
            else
            {
                ptr =start;

                while(ptr->next!= NULL)
                    ptr = ptr->next;

                ptr->next = temp;
                ptr->next->prev = ptr;
            }
        }
        else
        {
            printf("\n enter the element at which data is to be stored : ");
            int d2;

            scanf("%d",&d2);

            printf("\n enter 'b' to enter at before or 'a' for after : ");
            scanf("%s",&c);

            ptr = start;

            while(ptr->data != d2)
                ptr = ptr->next;

            if(c=='b')
            {
                temp->prev= ptr->prev;
                ptr->prev->next = temp;
                temp->next = ptr;
                ptr->prev = temp;
            }
            else if(c=='a')
            {
                temp->prev= ptr;
                temp->next =ptr->next;
                temp->next->prev = temp;
                ptr->next =temp;
            }
        }
    }

    ptr =start;

    cout<<endl<<"the resultant linklist is :";
    while(ptr!=NULL)
    {
        printf("%d ",
               ptr->data);
        ptr = ptr->next;
    }

    cout<<"enter the number of items to be deleted : ";
    scanf("%d",&d);

    while(d--)
    {
        int d2;
        printf("\n enter the element to be deleted : ");
        scanf("%d",&d2);

        ptr =start;

        while(ptr->data != d2)
            ptr = ptr->next;

        if(ptr == start)
        {
            start = ptr->next;
            free(ptr);
        }
        else if(ptr->next == NULL)
        {
            ptr->prev->next = NULL;
            free(ptr);
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
        ptr =start;
        cout<<endl<<"the resultant linklist is :";
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }

return 0;
}
