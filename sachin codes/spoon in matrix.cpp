#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,r,c,flag,i,j;
	char s[102][102];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>s[i][j];
			}
		}
		flag=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c-4;j++)
			{
				if((s[i][j]=='s'||s[i][j]=='S')&&(s[i][j+1]=='p'||s[i][j+1]=='P')&&(s[i][j+2]=='o'||s[i][j+2]=='O')&&(s[i][j+3]=='o'||s[i][j+3]=='O')&&(s[i][j+4]=='n'||s[i][j+4]=='N'))
				{
					flag++;
					break;
				}
			}
		}
		for(i=0;i<c;i++)
		{
			for(j=0;j<r-4;j++)
			{
				if((s[j][i]=='s'||s[j][i]=='S')&&(s[j+1][i]=='p'||s[j+1][i]=='P')&&(s[j+2][i]=='o'||s[j+2][i]=='O')&&(s[j+3][i]=='o'||s[j+3][i]=='O')&&(s[j+4][i]=='n'||s[j+4][i]=='N'))
				{
					flag++;
					break;
				}
			}
		}
		if(flag==0)
		printf("There is indeed no spoon!\n");
		else
		printf("There is a spoon!\n");
	}
	return 0;
}		
