 #include<iostream>
#define n 5
using namespace std;
int print(struct stack *);
struct stack
{
	int array[n];
	int top;
};
int push(struct stack *s,int data )
{
	
	if(s->top==n-1)
{
	cout<<"overflow";
	return 0;}
	else
	s->array[++(s->top)]=data;
	//cout<<"hello";
	return 0;
}

int pop(struct stack *s)
{
	int data;
	if(s->top==-1)
{
	cout<<"underflow";
	return 0;}
	else 
	data=s->array[s->top--];
	cout<<"deleted data is = "<<data;
	return 0;
}

int main()
{
    struct stack s;
	int i,data,c;
	s.top = -1;
	do{
		cout<<"enter your choice as 1-push....2-pop....3-exit\t";
		cin>>c;
		switch(c)
		{
			case 1: cout<<"enter data you want to insert\t";
			        cin>>data;
			        push(&s,data);
			        break;
			case 2: pop(&s);
			        break;
			case 3: break;		        
		}
	}
	while(c!=3);
	print(&s);
}
int print(struct stack *s)
{
	
	cout<<"final stack elements are/t";
    for(int i=s->top;i >= 0;i--)
	{
		cout<<s->array[i]<<"\t";
	}
}

