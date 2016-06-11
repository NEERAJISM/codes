#include<iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

int main()
{
    int n,i,d;
    scanf("%d",&n);
    struct node *start = NULL,*ptr,*par;
    int n1 = n;
    while(n1--)
    {
        scanf("%d",&d);

        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = d;
        temp->link = NULL;

        if(start == NULL)
            start = temp;
        else
        {
            temp->link = start;
            start  =temp;
        }
    }


    int k,dd;
    cout<<endl<<"enter thew repeatation of the testing : ";
    scanf("%d",&dd);

    while(dd--)
    {
        printf("enter the value of k : ");
        scanf("%d",&k);

        if(k>n)
            printf("\nthe value of k is out of bounds\n");
        else if(k==1)
        {
            ptr = start;
            par = NULL;
            while(ptr->link != NULL)
            {
                par =ptr;
                ptr =ptr->link;
            }

            par->link = start;
            ptr->link = start->link;
            start->link = NULL;
            start = ptr;
        }
        else
        {
            struct node *ptr1 = start,*par1 = NULL;
            struct node *ptr2 = start,*par2 = NULL;

            int count1 = k-1;
            int count2 = n-k;

            while(count1--)
            {
                par1= ptr1;
                ptr1 = ptr1->link;
            }

            while(count2--)
            {
                par2 = ptr2;
                ptr2 = ptr2->link;
            }

            cout<<"ptr1 : "<<ptr1->data<<" prt2 :"<<ptr2->data<<endl;

            if(ptr1==ptr2)
                printf("both are same nodes \n");
            else if(ptr1->link == ptr2)
            {
                par2 = ptr2->link;
                par1->link = ptr2;
                ptr2->link = ptr1;
                ptr1->link = par2;
            }
            else if(ptr2->link == ptr1)
            {
                par1= ptr1->link;
                par2->link = ptr1;
                ptr1->link = ptr2;
                ptr2->link = par1;
            }
            else
            {
                struct node* temp2;
                cout<<"arbitary "<<par1->data<<"***"<<par2->data<<endl;
                temp2 = ptr2->link;
                par1->link = ptr2;
                ptr2->link = ptr1->link;
                par2->link = ptr1;
                ptr1->link = temp2;
            }
        }

        ptr = start;
        cout<<endl<<"the modified list is : ";
        while(ptr!= NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
return 0;
}
