//infix to prefix conversion
#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,top=0,k=0,n;
    char  q[100],stack[100];
    printf("enter the given infix expression with extra ')' at the right end \n");

    gets(q);
    n=strlen(q)-1;
    char *a =(char*)malloc(n*sizeof(char));

    top=top+1;
    stack[top]='(';

    while(q[i]!=NULL)
    {   printf("%c**\n",q[i]);
        printf("%c---\n",stack[top]);
        if(q[i]=='(')
        {
            top=top+1;
            stack[top]=q[i];
        }
        else if(q[i]=='^')
        {
            while(stack[top]!='('||stack[top]!=')'||stack[top]!='+'||stack[top]!='-'||stack[top]!='*'||stack[top]!='/')
            {
                a[k]==stack[top];
                k++;
                top--;
            }
            top=top+1;
            stack[top]=q[i];
        }

        else if(q[i]=='*'||q[i]=='/')
        {
            while(stack[top]!='('||stack[top]!=')'||stack[top]!='+'||stack[top]!='-')
            {
                a[k]==stack[top];
                k++;
                top--;
            }
            top=top+1;
            stack[top]=q[i];
        }

        else if(q[i]=='+'||q[i]=='-')
        {   printf("%c",stack[top]);
            if(stack[top]=='(')
            {
                while(stack[top]!='('||stack[top]!=')')
                {
                    a[k]==stack[top];
                    k++;
                    top--;
                }
            top=top+1;
            stack[top]=q[i];
            }
        }

        else if(q[i]==')')
        {
            while(stack[top]!='(')
            {
                a[k]==stack[top];
                k++;
                top--;
            }
            top=top-1;
            if(top==0)
            break;
        }

        else
        {
            a[k]=q[i];
            printf("%c*/*\n",a[k]);
            k++;
        }
    i++;
    }

    printf("the equivalent prefix expression is\n");
    i=n-1;

    while(i>=0)
    {
        printf("%c ",a[i]);
        i--;
    }
return 0;
}








