#include<iostream>
#include<malloc.h>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

void push(struct node **front,struct node **rear,int item)
{
	struct node *temp,*temp2;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=NULL;
	if(*front==NULL)
	{
		*rear=temp;
		*front=temp;
	}
	else
	{
	
	temp2=*rear;
	temp2->link=temp;
	*rear=temp;
}
}

void pop(struct node **front,struct node **rear)
{
	struct node *temp;
	temp=*front;
	if(temp==NULL)
	{
		cout<<"underflow\n";
	}
	

	cout<<"deleted element is =  "<<temp->data<<"\n";
	*front=temp->link;
	
}

void print(struct node **front,struct node **rear)
{
	struct node *temp;
	int c=0;
	temp=*front;
	cout<<"current elements are \n";
	while(temp!=NULL)
	{
       cout<<temp->data<<"\t";
       	temp=temp->link;
		c++;
	}
	cout<<"no of elements are =  "<<c<<"\n";
}

int main()
{
	struct node *f,*r;
	f=NULL;
	r=NULL;
	int item,c;
	do
	{
	
	cout<<"enter the choice as 1-push 2-pop 3-exit\n";
	cin>>c;
	switch(c)
	{
		case 1:  cout<<"enter the item\n";
		         cin>>item;
		         push(&f,&r,item);
		         print(&f,&r);
		         break;
		  
		case 2:  pop(&f,&r);
		         print(&f,&r);
		         break;
		         
		case 3:  print(&f,&r);
		         break;
				 
		default: cout<<"wrong choice so enter again\n";		          
	}
   }
   while(c!=3);
   
   return 0;
}


