#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	int t,i,hole;
	char s[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		i=0;
		hole=0;
		while(i<strlen(s))
		{
			if(s[i]=='A')
			hole+=1;
			if(s[i]=='B')
			hole+=2;
			if(s[i]=='D')
			hole+=1;
			if(s[i]=='O')
			hole+=1;
			if(s[i]=='P')
			hole+=1;
			if(s[i]=='Q')
			hole+=1;
			if(s[i]=='R')
			hole+=1;
            
			i++;
		}
		printf("%d",hole);
		printf("\n");
		
	}
	return 0;
	
	
}
