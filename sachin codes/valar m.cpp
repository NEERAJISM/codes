#include<bits/stdc++.h>
using namespace std;
long long int ab(long long int xx)
{
	if(xx<0)
	return (-xx);
	else
	return xx;
}
int main()
{
	long long int x,y,n,c,s,x1,y1,i,a[100002],b[100002];
	vector<pair<long long int ,long long int> >v;
	scanf("%lld%lld",&n,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		
	}
	x=0;y=0;
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	if(n%2==1)
	{
		x=a[(n+1)/2];
		y=b[(n+1)/2];
	}
	else
	{
		x=(a[n/2]+a[(n+2)/2])/2;
			y=(b[n/2]+b[(n+2)/2])/2;
	}
	

	s=0;
	for(i=1;i<=n;i++)
	{
		x1=a[i];    y1=b[i];
		s+=(ab(x-x1)+ab(y-y1));
	}
	printf("%lld\n",s*c);
}
