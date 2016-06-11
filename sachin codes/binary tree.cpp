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

void inorder(struct node *root)
{
	if(!root)
	return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder(struct node *root)
{
	if(!root)
	return ;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node *root)
{
	if(!root)
	return ;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
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

void levelorder2(struct node *root)
{
	if(!root)
	return ;
	
	struct node *q[100];   int front=0; int back=0;  q[front]=root;
	
	while(front<=back)
	{
		struct node *node=q[front];    printf("%d ",node->data);
		front++;
		if(node->left)
		{
			q[++back]=node->left;
		}
		if(node->right)
		{
			q[++back]=node->right;
		}
	}
}

int height(struct node *root)
{
	if(!root)
	return 0;
	return (1+max(height(root->left),height(root->right)));
}

int height2(struct node *root)
{
	if(!root)
	return 0;
	queue<struct node *>q;      int h=0;
	q.push(root);
	
	while(1)
	{
		int count=q.size();
		if(count==0)
		return h;
		else
		{
			h++; cout<<"h="<<h<<endl;
		}
		
		while(count>0)
		{
			struct node *node=q.front();
			q.pop();
			
			if(node->left)
			q.push(node->left);
			if(node->right)
			q.push(node->right);
			
			count--;
		}
	}
}

struct node *lca(struct node *root,int a,int b)
{
	if(root==NULL)
	return NULL;
	
	if(root->data==a||root->data==b)
	return root;
	
	struct node *left_search=lca(root->left,a,b);
	struct node *right_search=lca(root->right,a,b);
	
	if(left_search&&right_search)
	return root;
	else if(left_search)
	return root->left;
	else if(right_search)
	return root->right;
}

int find_level(struct node *root,int a)
{
	if(root==NULL)
	return -1;
	
	queue<struct node *>q;
	q.push(root);   int level=0;
	while(1)
	{
		int count=q.size();
		if(count==0)
		return -1;
		else 
		level++;
		
		while(count>0)
		{
			struct node *node=q.front();
			q.pop();
			
			if(node->data==a)
			return level;
			
			if(node->left)
			q.push(node->left);
			if(node->right)
			q.push(node->right);
			
			count--;
		}
	}
}

//void print_root_to_leaf_paths(struct node *root,)

int main()
{
	struct node *root=NULL;
	root=Newnode(1);
	root->left=Newnode(2);
	root->right=Newnode(3);
	root->left->left=Newnode(4);
	root->left->right=Newnode(5);
	root->right->left=Newnode(6);
	root->right->right=Newnode(7);
	
	cout<<"inorder=";
	inorder(root);
	printf("\n");
	cout<<"preorder=";
	preorder(root);
	printf("\n");
	cout<<"postorder=";
	postorder(root);
	printf("\n");
	cout<<"levelorder2=";
	levelorder2(root);
	printf("\n");
	cout<<"height=";
	cout<<height2(root)<<endl;
	
	cout<<"enter the two number to find their lca\n";
	int a,b;
	cin>>a>>b;
	struct node *xx=lca(root,a,b);
	cout<<"lca is="<<xx->data<<endl;
	
	cout<<"enter a number whose level you want to find\n";
	cin>>a;
	int lev=find_level(root,a);
	cout<<"level="<<lev<<endl;
	
	return 0;
}
