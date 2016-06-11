#include<bits/stdc++.h>
using namespace std;

double arr[2016];

int main()
{
	long long int T,no,p,m,b,n,prev_n,t,a,i;
	double r1,r2,r3,r4,x,y,z,ans,res,u,prev_ans,ans1,ans2,val,pos;
	scanf("%lld",&T);
	scanf("%lld%lld%lld%lld",&no,&p,&m,&b);
	scanf("%lf%lf%lf%lf",&r1,&r2,&r3,&r4);
	//cout<<r1<<r2;
	
	if(r1<=1000&&r2<=1000&&r3<=1000&&r4<=1000&&T<=1000)
	{
		arr[1]=r1; arr[2]=r2; arr[3]=r3; arr[4]=r4;
	
	if(r1==r2)
	{
		for(i=5;i<=2012;i++)
		arr[i]=0;
	}
	else{
		
		for(i=5;i<=2012;i++)
		{
			x=( (r1*arr[i-1])+(r2*r1)-(r2*arr[i-1]) )/(r1*r2*arr[i-1]);
			y=(r1-r2-arr[i-1])/(r1*r2*arr[i-1]);
			if(y<0)
			y=-y;
			z=2*sqrt(y);
			ans1=(1/(x+z));
			ans2=(1/(x-z));
			//cout<<"ans1="<<ans1<<"ans2="<<ans2<<endl;
			if(ans2<0)
			arr[i]=ans1;
			else if(abs(ans2-arr[i-2])<=abs(ans1-arr[i-2]))
			arr[i]=ans1;
			else
			arr[i]=ans2;
		}
	}
		//for(i=5;i<=12;i++)
		//cout<<arr[i]<<endl;
		
			res=0; prev_n=no; 
	
			for(t=1;t<=T;t++)
			{
				n= (p*prev_n)%m+b;
				
				res+=arr[n];
				
				prev_n=n;
			}
		
	printf("%.6lf\n",res);
	}
	else{
		
	
	prev_n=no;
	x= 4*r1*r2*(r1-r2);
	y= (r1+r2)*(r1+r2);
	z= (r1-r2)*(r1-r2);
	
	val=(x/(r3*z))-(y/z)+1;
	pos=sqrt(val)/2;
	//cout<<"pos="<<pos<<endl;

		if(r4>=r3)
		{
			res=0;
			for(t=1;t<=T;t++)
			{
				n= (p*prev_n)%m+b;
				
				if(n==1)
				ans=r1;
				else if(n==2)
				ans=r2;
				else if(n==3)
				ans=r3;
				else if(n==4)
				ans=r4;
				else if(n>=3+pos)
				{
					a=n-3-pos;
					u=(double)((4*a*a)-1);
					ans= x/(y+(u*z));
					//cout<<ans<<endl;
				}
				else if(n>4&&n<3+pos)
				{
					a=3+pos-n;
					u=(double)((4*a*a)-1);
					ans= x/(y+(u*z));
				}
				
				prev_n=n;
				res+=ans;
			}
		}
		else
		{
			res=0;
			for(t=1;t<=T;t++)
			{
				n= (p*prev_n)%m+b;
				
				if(n==1)
				ans=r1;
				else if(n==2)
				ans=r2;
				else if(n==3)
				ans=r3;
				else if(n==4)
				ans=r4;
				else
				{
					a=n-3+pos;
					u=(double)((4*a*a)-1);
					ans= x/(y+(u*z));
				}
				
				prev_n=n;
				res+=ans;
			}
		}
	printf("%.6lf\n",res);}
	return 0;
}  
