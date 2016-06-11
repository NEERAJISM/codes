/*concantenate two strings using pointers*/
#include<stdio.h>
#include<string.h>
void conc(char *,char *);
int main()
{

    char a[50],b[50];
    printf("enter the string a and b");
    gets(a);
    gets(b);
    conc(&a,&b);
    printf("new string = %s",a);
return 0;
}

void conc(char *a,char *b)
{
    while(*a)
        a++;
    while(*b)
    {
        *a=*b;
        b++;
        a++;
    }
}



