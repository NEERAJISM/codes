#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	float r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f",&r);
		float x1,y1,x,y,x2,y2;
		float s1,s2,s12;
		scanf("%f%f",&x,&y);
		scanf("%f%f",&x1,&y1);
		scanf("%f%f",&x2,&y2);
		s12=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
		s1=sqrt(pow((x1-x),2)+pow((y1-y),2));
		s2=sqrt(pow((x-x2),2)+pow((y-y2),2));
		
		if(s12<=r&&s1<=r)
		printf("yes\n");
		else if(s12<=r&&s2<=r)
		printf("yes\n");
		else if(s1<=r&&s2<=r)
		printf("yes\n");
		elseN
		printf("no\n");
	}
	return 0;
}
