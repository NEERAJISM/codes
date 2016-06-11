#include<stdio.h>
int main()
{
	int x;
	double b;
	
	scanf("%d%lf",&x,&b);
	
	if(x%5!=0)
		printf("%lf",b);
	else
		printf("%lf",b-x-0.5);
		
		return 0;

}
