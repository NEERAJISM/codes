#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *Newnode(int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void levelorder(struct node *root)
{
	if(!root)
	return ;
	
	queue<struct node *> q;
	q.push(root);
	
	while(!q.empty())
	{
		struct node *node=q.front();    printf("%d ",node->data);
		q.pop();
		if(node->left)
		q.push(node->left);
		if(node->right)
		q.push(node->right);
	}
}

int find_it(int a[],int start,int end,int x)
{
	for(int i=start;i<=end;i++)
	if(a[i]==x)
	return i;
	
}

//int pre_index=0;

struct node *build_tree(int in[],int pre[],int start,int end,int *pre_index)
{
	if(start>end)
	return NULL;
		
		int val=pre[*pre_index];
		(*pre_index)++;
		
		struct node *tnode=Newnode(val);
		int idx=find_it(in,start,end,tnode->data);
		tnode->left=build_tree(in,pre,start,idx-1,pre_index);
		tnode->right=build_tree(in,pre,idx+1,end,pre_index);
		return tnode;

}

int main()
{
	int in[50],pre[50],i,n;
	cout<<"enter the number of elements\n";
	cin>>n;
	cout<<"enter inorder traversal\n";
	for(i=0;i<n;i++)
	cin>>in[i];
	cout<<"enter preorder traversal\n";
	for(i=0;i<n;i++)
	cin>>pre[i];
	
	int pre_index=0;
	struct node *root=build_tree(in,pre,0,n-1,&pre_index);
	cout<<"hello\n";
	levelorder(root);
	return 0;
}



