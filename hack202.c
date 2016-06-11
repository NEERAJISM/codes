#include<stdio.h>
#include<string.h>
char s[10000000],sub1[10000000];
int i=0,n,m,j=0,flag=0,k,l,o=0;
int main()
{

	
		
		scanf("%s",s);
		
		scanf("%s",sub1);
			
	n=strlen(s);
	m=strlen(sub1);
		
	for(i=0;i<n;i++)
	{
		if(s[i]==sub1[j])
			{	
				if(flag==0)
					k=i;		
				flag++;
				j++;
				
				
			
				
				if(flag==m)
					break;												
			}
		else
			{
				if(s[i]==sub1[0])
					i--;	
				flag=0;
				j=0;
			}
	}
	
	if(flag==m)
		{
			
			printf("YES\n");
			
			for(i=0;i<k;i++)
				printf("%c",s[i]);
				
			for(i=m-1;i>=0;i--)
				printf("%c",sub1[i]);
				
				i=k+m-1;
				while(i++<=n)
					printf("%c",s[i]);
		}
	else
		printf("NO\n");
		
	return 0;
			
}

