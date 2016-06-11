#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int binary(char c[],char x,int l,int u)
{
	int count=0,mid;
	while(l<=u){
         mid=(l+u)/2;
         if(x==c[mid]){
             count=1;
             break;
         }
         else if(x<c[mid]){
             u=mid-1;
         }
         else
             l=mid+1;
    }
    return count;
}
int main()
{
	char c[100002],d[100002];
	int i,t,flag,n,m,j,flag2;
	scanf("%d",&t);
	while(t--)
	{
		cin>>c>>d;
		n=strlen(c);
		m=strlen(d);
		flag=0;
		for(i=0;i<m;i++)
		{
			flag2=binary(c,d[i],0,n-1);
			if(flag2>0)
			{
				flag++;
				break;
			}
		}
	
		if(flag>0)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
