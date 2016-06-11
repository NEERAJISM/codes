#include<stdio.h>
#include<string.h>
int main()
{
    long long int a,flag,i,t,x,temp,d,p;
    char c[100000];

    scanf("%lld",&t);
    while(t-->0)
    {
    	temp=0;
        d=0;
        p=0;
        scanf("%lld",&a);
        flag=0;

        while(a>0)
        {
            p=a%10;
            
            a=a/10;
				

            if(flag==0)
            {
                temp=p;
                flag++;
                if(a==0)
                {
                   c[d]=123-temp;
                   
                   flag++;
					d++;
					break;                
				}
            }
            else if(flag==1)
            {
            	if(1)
            	{
                temp=temp+p*10;
                
                flag++;
            	}
            	if(flag==2)
                {
                c[d]=123-temp;
                d++;
                flag=0;
                }
            	
            }
            
        }

        for(i=d-1;i>=0;i--)
        printf("%c",c[i]);
        
        printf("\n");
    }
return 0;
}






