#include<stdio.h>
#include<math.h>
void value();
float c,d,e,f,a,b,avg,val;
int main()
{
	int n=1;
	scanf("%f%f%f%f",&c,&d,&e,&f);
	scanf("%f%f",&a,&b);
	
	avg=(a+b)/2;
	printf("%f*****",avg);
	
	while(n++<=25)
	{
		value();
		if(val<0)
			b=avg;
		else
			a=avg;
			
			avg=(a+b)/2;
			printf("%f",avg);
	}
	
	printf("%f",avg);
return 0;	 
}

void value()
{
	val=(c*(pow(avg,3)))+(d*(pow(avg,2)))+(e*(avg))+f;
}
