#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;

};
struct node* ptr;
struct node* save;
struct node* new1;
struct node* root=NULL;

void insert(int d)
{
    int flag;
    new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = d;
    new1->left = NULL;
    new1->right = NULL;

    if(root == NULL)
    {    root = new1;
         printf("****");
    }
    else
    {
        ptr= root;
        if(root->left==NULL&&root->right==NULL)
        {
            if(d<ptr->data)
            {
                root->left =new1;
            }
            else
            {
                root->right =new1;
            }
        }
        else
        {
            while(5)
            {

                if(d<ptr->data)
                {
                    flag=1;
                    save = ptr;
                    ptr = ptr->left;
                    if(ptr==NULL)
                        break;
                }
                else
                {
                    flag=0;
                    save =ptr;
                    ptr = ptr->right;
                    if(ptr==NULL)
                        break;
                }
            }
            if(flag==1)
                save->left=new1;
            else
                save->right =new1;
        }

    }
}

preorder()
{
    struct node* a1[100];
    int top= 0;
    a1[top]=root;
    ptr=root;

    while(ptr!=NULL)
    {

        save=ptr;
        printf("%d** ",ptr->data);
        if(ptr->right!=NULL)
        {
            top++;
            a1[top]=ptr->right;
        }
        if(ptr->left!=NULL)
            ptr=ptr->left;
        else
        {
            ptr=a1[top];
            top--;
        }
    }

}

int main()
{
    int i,item;

    for(i=0;i<10;i++)
    {
        scanf("%d",&item);
        insert(item);
    }

    preorder();

return 0;
}
