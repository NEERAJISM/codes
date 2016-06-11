#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
}
int bstsearch(struct node **root,int item)
{
	flag=0;
	if(root==NULL)
	return NULL;
	else if(root->data==item)
	flag=1;
	else if(root->data>item)
	bstsearch(&root->right,item);
	else if(root->data<item)
	bstsearch(&root->left,item);
	return flag;
}
int bstinsert(struct node **root,int item)
{
	if(root==NULL)
	{
		root=(struct node *) malloc (sizeof(struct node));
		root->data=item;
		root->right=NULL;
		root->left=NULL;
	}
	else if(root->data>=item)
	bstinsert(&root->right,item);
	else if(root->data<item)
	bstinsert(&root->left,item);
}
int maximum(struct node **root)
{
	struct node *temp;
	temp=*root;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return (temp->data);
}
int minimum(struct node **root)
{
	struct node *temp;
	temp=*root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return (temp->data);
}
void inorder(struct node **root)
{
	struct node *temp;
	temp=*root;
	if(temp!=NULL)
	{
		inorder(&temp->left);
		cout<<temp->data;
		inorder(&temp->right);
	}
}
int main()
{
	
}






