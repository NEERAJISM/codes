#include<stdio.h>
#include<stdlib.h>
struct node
    {
        int data;
        struct node* link;
    };
int main()
{
    int i;
    struct node *start, *new, *ptr;
    char a;
    start=NULL;
    while(1)
    {
        printf("enter i to insert, v to view , e to exit\n");
        scanf("%s",&a);
        if(a=='i')
        {
            new = (struct node*)malloc(sizeof(struct node));
            printf("enter the data\n");
            scanf("%d",&new->data);
            new->link= NULL;
            if(start==NULL)
                start= new;
            else
            {
                ptr= start;
                while(ptr->link!=NULL)
                    ptr = ptr->link;

                    ptr->link = new;
            }
        }
        if(a=='v')
        {
            ptr= start;
            while(ptr!=NULL)
            {
                printf("%d ",ptr->data);
                 ptr= ptr->link;
            }
        }
        if(a=='e')
            break;
    }
return 0;
}
