#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
}
int main()
{
	int n,x,y,i,count,a[103],b[103],j,k,ans;
	long double  p,q,r;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	count=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				//p=sqrt(((a[i]-a[j])*(a[i]-a[j]))+((b[i]-b[j])*(b[i]-b[j])));//cout<<"p="<<p;
				//q=sqrt(((a[j]-a[k])*(a[j]-a[k]))+((b[j]-b[k])*(b[j]-b[k])));//cout<<"q="<<q;
				//r=sqrt(((a[k]-a[i])*(a[k]-a[i]))+((b[k]-b[i])*(b[k]-b[i])));//cout<<"r="<<r;
					ans=collinear(a[i],b[i],a[j],b[j],a[k],b[k]);
				if(ans==0)
				count++;//cout<<endl;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
