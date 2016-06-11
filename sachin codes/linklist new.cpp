#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

struct node *Newnode(int data)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=NULL;
	return newnode;
}

void print(struct node *head)
{
	struct node *temp=head;
	cout<<"here are the present elements\n";
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

struct node *merge_it(struct node *a,struct node *b)
{
	struct node *head=NULL;
	struct node *temp=NULL;
	while(a && b)
	{
		if(a->data<=b->data)
		{
			if(!head)
			{
				head=a;
				a=a->link;
				temp=head;
			}
			else
			{
				temp->link=a;
				a=a->link;
				temp=temp->link;
			}
		}
		else if(a->data>b->data)
		{
			if(!head)
			{
				head=b;
				b=b->link;
				temp=head;
			}
			else
			{
				temp->link=b;
				b=b->link;
				temp=temp->link;
			}
		}
	}
	if(a)
	{
		if(!head)
		head=a;
		else
		temp->link=a;
	}
	if(b)
	{
		if(!head)
		head=b;
		else
		temp->link=b;
	}
	return head;
}

struct node  *mergesort(struct node *head)
{
	if(!head)
	return head;
	if(!head->link)
	return head;
	
	struct node *sp=head;
	struct node *fp=head;
	
	int count=0;
	while(fp!=NULL)
	{
		fp=fp->link;
		count++;
	}
	if(count==2)
	{
		sp=head;
	}
	else
	{
		while(fp&&sp&&fp->link)
		{
			sp=sp->link;
			fp=fp->link->link;
		}
	}
	struct node *left;
	left=head;
	
	struct node *right;
	right=sp->link;
	sp->link=NULL;
	print(left);
	print(right);
	struct node *x=mergesort(left);
	struct node *y=mergesort(right);
	struct node *z=merge_it(x,y);
	return z;
}



void rev(struct node **head)
{
	struct node *curr=*head;
	struct node *prev=NULL;
	struct node *next;
	
	while(curr!=NULL)
	{
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	*head=prev;
}

struct node *find_mid(struct node *head)
{
	struct node *sp=head;
	struct node *fp=head;
	
	if(head==NULL)
	return NULL;
	
	while(fp!=NULL&&fp->link!=NULL)
	{
		fp=fp->link->link;
		sp=sp->link;
	}
	return sp;
}

struct node *find_intersection(struct node *head1,struct node *head2)
{
	struct node *a=head1;
	struct node *b=head2;
	
	struct node *int_head=NULL;
	struct node *temp=NULL;
	
	while(a!=NULL&&b!=NULL)
	{
		if(a->data==b->data)
		{
			if(int_head==NULL)
			{
				int_head=Newnode(a->data);
				temp=int_head;
			}
			else
			{
				temp->link=Newnode(a->data);
				temp=temp->link;
			}
			
			a=a->link;
			b=b->link;
		}
		else if(a->data<b->data)
		a=a->link;
		else if(a->data>b->data)
		b=b->link;
	}
	return int_head;
}

int main()
{
	int i,n,x;
	cout<<"enter the no. of elements\n";
	cin>>n;
	
	struct node *head=NULL;
	struct node *temp=NULL;
	cin>>x;
	head=Newnode(x);
	temp=head;
	
	for(i=2;i<=n;i++)
	{
		cin>>x;
		temp->link=Newnode(x);               //very important steps
		temp=temp->link;                      //very important steps
	}
	
	print(head);
	
	cout<<"mid element is\n";
	struct node *mid=find_mid(head);
	cout<<mid->data<<endl;
	
	
	cout<<"sorted list is\n";
	head=mergesort(head);
	print(head);
//	rev(&head);
//	print(head);
	
	cout<<"if you want to find the intersection of two linklists press 1 else 0\n";
	cin>>x;
	if(x==1)
	{
		struct node *head1=head;
		struct node *head2=NULL;
		struct node *temp=NULL;
		
		cout<<"enter the no. of elements\n";
		cin>>n;
		cin>>x;
		head2=Newnode(x);
		temp=head2;
		
		for(i=2;i<=n;i++)
		{
			cin>>x;
			temp->link=Newnode(x); 
			temp=temp->link;  
		}
		
		struct node *intersection_head=find_intersection(head1,head2);
		print(intersection_head);
	}
	
	return 0;
}
