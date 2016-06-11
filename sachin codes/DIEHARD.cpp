#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,h,a,i,count,flag;
	long long int max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&a);
		if(h==0||a==0)
		{
			printf("0\n");
			flag=1;
		}
		else{
		
		h=h+3;
		a=a+2;  
		          max=1;  flag=0;
		          
		while(1)
		{
			if(a>10&&h>5)
			{
				a=a-10;  h=h-5;
				max=max+2;
				a=a+2;    h=h+3;
			}
			else if(h>20&&a<=10)
			{
				a=a+5;
				h=h-20;
				max=max+2;
				a=a+2;   h=h+3;
			}
			else
			{
				printf("%lld\n",max);
				flag=1;
				break;
			}
			//cout<<h<<"  "<<a<<endl;
		}}
//		if(!flag)
//		printf("%lld\n",max);
	}
	return 0;
}
