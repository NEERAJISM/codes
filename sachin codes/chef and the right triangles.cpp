#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int n,i,x1,y1,x2,y2,x3,y3,m12,m23,m31,c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		m12=(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
		m23=(y3-y2)*(y3-y2)+(x3-x2)*(x3-x2);
		m31=(y3-y1)*(y3-y1)+(x3-x1)*(x3-x1);
		if(m12>m23&&m12>m31)
		{
			if(m12==m23+m31)
			c++;
		}
		if(m23>m12&&m23>m31)
		{
			if(m23==m12+m31)
			c++;
     	}
     	if(m31>m23&&m31>m12)
		{
			if(m31==m23+m12)
			c++;
	    }

	}
	printf("%d\n",c);
	return 0;
}
