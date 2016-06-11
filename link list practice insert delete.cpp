#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

void printlinklist(struct node* ptr)
{
    if(ptr == NULL)
        return;

    printlinklist(ptr->link);
    printf("%d ",ptr->data);
}

int main()
{
    int n,i,j,d;
    char c;
    struct node* start = NULL;
    struct node* ptr = NULL;

    while(1)
    {
        printf("Action : ");
        scanf("%s",&c);

        if(c == 'i')
        {
            printf("insert data : ");
            scanf("%d",&d);
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->data = d;
            temp->link = NULL;

            printf("insert at f or b or a: ");
            scanf("%s",&c);

            if(c=='f')
            {
                if(start == NULL)
                    start = temp;
                else
                {
                    temp ->link = start;
                    start = temp;
                }
            }
            else if(c=='b')
            {
                if(start == NULL)
                    start = temp;
                else
                {
                    ptr = start;

                    while(ptr->link != NULL)
                        ptr = ptr->link;

                    ptr->link = temp;
                }
            }
            else if(c=='a')
            {
                printf("insert the data at which new node is to be inserted : ");
                int t2d;
                scanf("%d",&t2d);

                printf("insert at forward or at backward :");
                scanf("%s",&c);

                if(c=='f')
                {
                    ptr = start;
                    struct node* par = NULL;

                    while(ptr->data != t2d)
                    {
                        par= ptr;
                        ptr = ptr->link;
                    }

                    if(par==NULL)
                    {
                        temp->link = start;
                        start = temp;
                    }
                    else
                    {
                        temp->link = ptr;
                        par->link = temp;
                    }
                }
                else if(c=='b')
                {
                    ptr =start;

                    while(ptr->data != t2d)
                    {
                        ptr = ptr->link;
                    }

                    if(ptr->link == NULL)
                    {
                        ptr -> link  =temp;
                    }
                    else
                    {
                        temp ->link = ptr->link;
                        ptr->link = temp;
                    }
                }
            }
        }
        else if(c=='v')
        {
            ptr = start;

            printf("r for reverse and n for normal : ");
            scanf("%s",&c);

            if(c=='n')
            {
                while(ptr!=NULL)
                {
                    printf("%d ",ptr->data);
                    ptr = ptr->link;
                }
            }
            else if(c=='r')
            {
                printlinklist(start);
            }
            printf("\n");
        }
        else if(c=='d')
        {
            int t2d;
            printf("type the data to be deleted : ");
            scanf("%d",&t2d);

            ptr = start;
            struct node* par = NULL;

            while(ptr->data != t2d)
            {
                par = ptr;
                ptr = ptr->link;
            }
            par->link = ptr->link;
        }
    }
return 0;
}
