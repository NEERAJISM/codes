#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

void append(struct node **q,int n)
{
	struct node *temp,*r;
	temp=*q;
	if(*q==NULL)
	{
		temp=(struct node *) malloc (sizeof(struct node));
		temp->data=n;
		temp->link=NULL;
		*q=temp;
	}
	else
	{
		temp=*q;
		while(temp->link!=NULL)
		{
			temp=temp->link;
	
		};
		r=(struct node *) malloc (sizeof(struct node));
		r->data=n;
		r->link=NULL;
		temp->link=r;
		
	}
}


int kreverse(struct node **q,int k)
{
	struct node *r,*s,*temp,*node_after_psition;
	temp=*q;
	node_after_psition=*q;
	int c=0;
		do
	{
		
		node_after_psition=node_after_psition->link;
		
		c++;
	}
	while(c!=k);
	r=node_after_psition;
	int d=0;
	do
	{
		s=r;
		r=temp;
		temp=temp->link;
		r->link=s;
		d++;
	}
	while(d!=k);
	*q=r;
	return 0;
}


void print(struct node **q)
{    
	struct node *temp;
	temp=*q;
	int counter=0;
	cout<<"currently available data is = ";
	while(temp!=NULL)
	{
		
		cout<<temp->data<<"\t";
		temp=temp->link;
		counter++;
	};
	cout<<"total no of data is = "<<counter;
}


int main()
{
	struct node *p;
	int c,n,x,k;
	p=NULL;
	
	do{
		cout<<"enter the choice as 1-append  2-kreverse   3-exit\n";
		cin>>c;
		switch(c)
		{
			case 1: cout<<"enter the data\n";
			        cin>>n;
			        append(&p,n);
			        break;
			        
	
					
			case 2: cout<<"enter the position";
			        cin>>k;
			        cout<<"in the reversed linklist";
			        kreverse(&p,k);
					print(&p);
					break;		
					
			case 3: print(&p);
			        break;
					
			default : cout<<"wrong choice... ";				        
		}
	}
	while(c!=3);
	return 0;
}
