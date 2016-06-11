#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1,n=50;
char stack[50];
void push(char item)
{
	if(top==n-1)
	{
		printf("OVERFLOW\n");
		exit(1);
	}
	else
    {
		top++;
		stack[top]=item;
	}
}
char pop()
{
	char item;
	if(top==-1)
	{
		printf("UNDERFLOW\n");
		exit(1);
	}
	else
	{
		item=stack[top];
		top--;
		return (item);
	}
}
int main()
{
	int e=1,j=0,l;
	char c[50],p[50];
	printf("enter string: ");
	gets(c);
	int i=0,item;
	l=strlen(c);
	c[l]='#';
	top=-1;
	while(e)
	{	printf("%d c=%c\n",i,c[i]);
		if(c[i]=='+' || c[i]=='-')
		{	printf("in + loop");
			while(top!=-1)
			{
				p[j]=pop();
				j++;
			}
			push(c[i]);
			i++;
		}
		else if(c[i]=='*'||c[i]=='/' )
		{	printf("in * loop");
			while((stack[top]=='*' || stack[top]=='/'||stack[top]=='^')&& top!=-1)
			{
				p[j]=pop();
				j++;
			}
			push(c[i]);
			i++;
		}
		else if(c[i]=='^')
		{	printf("in  ^ loop");
			push(c[i]);
			i++;
		}
		else if(c[i]=='#')
		{
			while(top!=-1)
			{
				p[j]=pop();
				j++;

			}
			e=0;
			p[j]=(int)NULL;
		}
		else if(c[i]>='a' || c[i]<='z')
		{
		    printf("in a loop");
			p[j]=c[i];
			j++;
			i++;

		}
    }
	puts(p);
return 0;
}

