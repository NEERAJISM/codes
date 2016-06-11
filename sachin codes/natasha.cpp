#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
int main()
{
	double ab,om,x,p,y,r2,ans,angle,ans1,ans2;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf",&ab,&om);
		x=ab/2;  p=om;
		
		angle=atan(x/p);
		angle=angle*2;
		
		r2=x*x+p*p;
		
		ans=((angle/2)*r2)-(x*p);
		
		printf("%.6lf\n",ans);
	}
	return 0;
}
