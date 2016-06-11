#include<bits/stdc++.h>
using namespace std;

double increasing_function(double a,double b,double c)
{
	double d = (c*(b-a)) + ((b*b-a*a)/2);
	return d;
}

double decreasing_function(double a,double b,double c)
{
	double d = (c*(b-a)) + ((a*a-b*b)/2);
	return d;
}

int main()
{
	int t;
	double T1,T2,t1,t2,ans,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&T1,&T2,&t1,&t2);
		//cin>>T1>>T2>>t1>>t2;
		
		if(t1==0&&t2==0)
		ans=0;
		else if(t2==0&&t1!=0)
		{
			if(t1>T2)
			{
				if(T1<=T2)
				{
					ans=decreasing_function(0,min(t1,T1),T2);
					ans=ans/(T1*T2);
				}
				else
				{
					ans=decreasing_function(0,T2,T2);
					ans=ans/(T1*T2);
				}
			}
			else
			{
				if(T2>=T1+t1)
				ans=t1/T2;
				else if(T1>=T2)
				{
					ans=increasing_function(0,min(t1,T1),0) + t1*(T2-t1);
					ans=ans/(T1*T2);
				}
				else if(T2>T1)
				{
					ans=t1*(T2-t1) + decreasing_function(T2-t1,T1,T2);
					ans=ans/(T1*T2);
				}
			}
		}
		else if(t1==0&&t2!=0)
		{
			if(t2>T1)
			{
				if(T2<=T1)
				{
					ans=decreasing_function(0,min(t2,T2),T1);
					ans=ans/(T1*T2);
				}
				else
				{
					ans=decreasing_function(0,T1,T1);
					ans=ans/(T1*T2);
				}
			}
			else
			{
				if(T1>=T2+t2)
				ans=t2/T1;
				else if(T2>=T1)
				{
					ans=increasing_function(0,min(t2,T2),0) + t2*(T1-t2);
					ans=ans/(T1*T2);
				}
				else if(T1>T2)
				{
					ans=t2*(T1-t2) + decreasing_function(T1-t2,T2,T1);
					ans=ans/(T1*T2);
				}
			}
		}
		else if(t1!=0&&t2!=0)
		{
			if(t1>=T2&&t2>=T1)
			ans=1;
			else if(t1>=T2&&T2>=T1)
			{
				t2=min(t2,T1);
				ans = t2*T2 + decreasing_function(t2,T1,T2+t2);
				ans = ans/(T1*T2);
			}
			else if(t2>=T1&&T1>=T2)
			{
				t1=min(t1,T2);
				ans = t1*T1 + decreasing_function(t1,T2,T1+t1);
				ans = ans/(T1*T2);
			}
			else
			{
				if(T2>=T1+t1)
				{
					t2=min(t2,T1);   //x=min(t1+t2,T2);
					ans = increasing_function(0,t2,t1) + (T1-t2)*(t1+t2);
					ans=ans/(T1*T2);
				}
				else if(T1>=T2+t2)
				{
					t1=min(t1,T2);   //x=min(t1+t2,T1);
					ans = increasing_function(0,t1,t2) + (T2-t1)*(t1+t2);
					ans=ans/(T1*T2);
				}
				else if(T2>=T1)
				{
					//x=min(t1+t2,T2);
					if(t2>=T1)
					ans = increasing_function(0,T2-t1,t1) + (T1-T2+t1)*T2;
					else
					ans = increasing_function(0,t2,t1) + (T2-t1-t2)*(t1+t2) + decreasing_function(T2-t1,T1,t2+T2);
					
					ans = ans/(T1*T2);
				}
				else if(T1>T2)
				{
					//x=min(t1+t2,T1);
					if(t1>=T2)
					ans = increasing_function(0,T1-t2,t2) + (T2-T1+t2)*T1;
					else
					ans = increasing_function(0,t1,t2) + (T1-t1-t2)*(t1+t2) + decreasing_function(T1-t2,T2,t1+T1);
					
					ans = ans/(T1*T2);
				}
			}
			
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}
