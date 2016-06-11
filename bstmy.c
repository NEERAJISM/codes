#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node *root,*ptr,*par;

int find(int d)
{
    int m=0;
    par=NULL;
    ptr=root;

    if(ptr->data==d)
    m=1;
    else
    {
        par=root;

        if(ptr->data==d)
            ptr=ptr->left;
        else
            ptr=ptr->right;

        while(ptr!=NULL||m==1)
        {
            if(ptr->data==d)
                m=1;
            else
            {
                par=ptr;
                if(ptr->data==d)
                    ptr=ptr->left;
                else
                    ptr=ptr->right;
            }
        }
    }
    return m;
}

void insert()
{
    int m1=0;
    root=NULL;

    struct node* new =(struct node*)malloc(sizeof(struct node));

    printf("enter the data\n");
    scanf("%d",&new->data);

    new->left = NULL;
    new->right= NULL;

    if(root==NULL)
        root = new;
    else
    {
        m1= find(new->data);
        if(m1==0)
        {
            if(new->data>par->data)
                par->right=new;
            else
                par->left=new;
        }
    }
}

int main()
{
    char a;
    while(1)
    {
        printf("enter\ni to to insert,\ne to exit\n");
        scanf("%s",&a);
        if(a=='i')
        {
            insert();
        }
        if(a=='e')
            break;
    }
return 0;
}
