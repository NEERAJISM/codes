#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

struct node
{
    int x;
    int y;
    struct node* link;
};

int main()
{
    int n,i,d,x1,y1;
    scanf("%d",&n);
    struct node *start1 = NULL,*start2=NULL,*ptr;

    scanf("%d%d",&x1,&y1);
for(i = 0;i<n;i++)
    {

        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->x  =x1;
        temp->y = y1;
        temp ->link =NULL;

        if(start1 == NULL)
            start1 = temp;
        else
        {
            temp ->link = start1;
            start1 = temp;
        }
    }

    ptr = start1;

    while(ptr!=NULL)
    {
        printf("(%d , %d)->",ptr->x,ptr->y);
        ptr = ptr->link;
    }

    cout<<endl;

    struct node *next1,*next2,*par;
    ptr = start1;

    int counter=2,pctr=2;
    while(1)
    {
        par = ptr;
        cout<<"par : "<<par->x<<" "<<par->y<<endl;
        next1 = ptr->link;
        next2 = next1->link;
        pctr = counter;

        while((next1->x == next2->x || next1->y == next2->y ) && counter == pctr)
        {
            cout<<"next1 : "<<next1->x<<" "<<next1->y<<endl;
            cout<<"next2 : "<<next2->x<<" "<<next2->y<<endl;

            par->link = next1->link;
            free(next1);

            if(next2->link == NULL)
                break;

            ptr = next2->link;
            next1 = next2;
            next2 =ptr;

            if(next1->x == next2->x)
                counter = 1;
            else
                counter = 2;
        }

        if(next2->link== NULL)
            break;

        ptr = next2;
    }

    ptr = start1;

    cout<<"\nthe modified version can be given as : ";
    while(ptr!=NULL)
    {
        printf("(%d , %d)->",ptr->x,ptr->y);
        ptr = ptr->link;
    }

return 0;
}
