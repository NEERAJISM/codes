#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T,no,p,m,b,n,prev_n,t,a,i;
	double r1,r2,r3,r4,x,y,z,ans,res,u,prev_ans,val,pos;
	scanf("%lld",&T);
	scanf("%lld%lld%lld%lld",&no,&p,&m,&b);
	scanf("%lf%lf%lf%lf",&r1,&r2,&r3,&r4);
	//cout<<r1<<r2;
	
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
					if(r1==r2)
					ans=0;
					else
					{
						a=n-3-pos;
						u=(double)((4*a*a)-1);
						ans= x/(y+(u*z));
					}
				
					//cout<<ans<<endl;
				}
				else if(n>4&&n<3+pos)
				{
					if(r1==r2)
					ans=0;
					else
					{
						a=3+pos-n;
						u=(double)((4*a*a)-1);
						ans= x/(y+(u*z));
					}

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
					if(r1==r2)
					ans=0;
					else
					{
						a=n-3+pos;
						u=(double)((4*a*a)-1);
						ans= x/(y+(u*z));
					}
					
				}
				
				prev_n=n;
				res+=ans;
			}
		}
	
	
	printf("%.6lf\n",res);
	return 0;
}   
