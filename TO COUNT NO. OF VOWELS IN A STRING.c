/*TO COUNT NO. OF VOWELS IN A STRING*/
#include<stdio.h>
#include<string.h>
int main()
{
    char a[50];
    int i=0,x,c=0;
    printf("enter the string\n");
    gets(a);
    strupr(a);
    while(a[i]!='\0')
    {
        x=a[i];
        if(x==65||x==69||x==73||x==79||x==85)
            {c=c+1;
            }
        i++;
    }
printf("the no. of vowels in the string is %d\n",c);
return 0;
}

