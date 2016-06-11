#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,i;
	float d,dt,ds;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f%f%f",&ds,&dt,&d);
		if(ds+dt<=d)
		printf("%f\n",d-ds-dt);
        else if(d+dt<=ds)
		printf("%f\n",ds-d-dt);
		else if(d+ds<=dt)
		printf("%f\n",dt-d-ds);
		else
		printf("0\n");
	}
	return 0;
}
