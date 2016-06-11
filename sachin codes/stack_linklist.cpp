#include<iostream>
#include<malloc.h>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

void push(struct node **top,int item)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
		temp->link=*top;
		*top=temp;
}

void pop(struct node **top)
{
	struct node *temp;
	temp=*top;
		if(temp==NULL)
	{
		cout<<"underflow\n";
	}
	cout<<"deleted element is =  "<<temp->data<<"\n";
	*top=temp->link;
	
}

void print(struct node **top)
{
	struct node *temp;
	int c=0;
	temp=*top;
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
	struct node *p;
	p=NULL;
	int item,c;
	do
	{
	
	cout<<"enter the choice as 1-push 2-pop 3-exit\n";
	cin>>c;
	switch(c)
	{
		case 1:  cout<<"enter the item\n";
		         cin>>item;
		         push(&p,item);
		        print(&p);
		         break;
		  
		case 2:  pop(&p);
		         print(&p);
		         break;
		         
		case 3:  print(&p);
		         break;
				 
		default: cout<<"wrong choice so enter again\n";		          
	}
   }
   while(c!=3);
   
   return 0;
}
