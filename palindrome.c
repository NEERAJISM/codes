/* to check string palindrome*/

#include<stdio.h>
#include<string.h>
int main()
{char a[100],b[100];
int p;
printf("enter the string ");
gets(a);
strcpy(b,a);
strrev(b);
p=strcmp(a,b);
if(p==0)
    printf("it is a palindrome");
else
    printf("it is not a palindrome");
return 0;

}
