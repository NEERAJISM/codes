#include<stdio.h>
#include<string.h>
int main()
{
    char s[100001];
    int n,i,j,count,flag=0,post,odd;
    gets(s);
    n=strlen(s);

    for(i=0;i<n;i++)
    {
        count=1;
        post=0;
        if(s[i]!='\0')
        {
            post=1;
            for(j=i+1;j<n;j++)
            {
                if(s[j]==s[i])
                {
                    count=count+1;
                    s[j]='\0';
                }
            }
        }

        if(count%2==1&&post==1)
            flag= flag+1;

        if(flag==2)
            break;
    }


    if(flag==2)
        printf("NO");
    else
        printf("YES");
return 0;
}




