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

int del(struct node **q,int x)
{
	struct node *temp,*old;
	temp=*q;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			if(temp==*q)
			{
				*q=temp->link;
				
				
			}
			else
			{
				old->link=temp->link;
			
				
			}return 0;
		}
		else
		{
		
		    old=temp;
	       	temp=temp->link;
	    }
	};
}


void reverse(struct node **q)
{
	struct node *temp,*r,*s;
	temp=*q;
	r=NULL;
	while(temp!=NULL)
	{
		s=r;
		r=temp;
		temp=temp->link;
		r->link=s;
	};
	*q=r;
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
	cout<<"total no of data is = "<<counter<<"\n";
}

int main()
{
	struct node *p;
	int c,n,x,k;
	p=NULL;
	
	do{
		cout<<"enter the choice as 1-append   2-delete   3-reverse  4-kreverse  5-exit\n";
		cin>>c;
		switch(c)
		{
			case 1: cout<<"enter the data\n";
			        cin>>n;
			        append(&p,n);
			        break;
			        
			case 2: cout<<"enter the data to be deleted\n";
			        cin>>x;
					del(&p,x);
					print(&p);
					break;
					
			case 3: cout<<"in the reversed linklist";
			        reverse(&p);
					print(&p);
					break;
					
					
			case 4: cout<<"enter the position\n";
			        cin>>k;
			        cout<<"in the reversed linklist\n";
			        kreverse(&p,k);
					print(&p);
					break;			
					
			case 5: print(&p);
			        break;
					
			default : cout<<"wrong choice...\n ";				        
		}
	}
	while(c!=5);
	return 0;
}
