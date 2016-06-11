#include<stdio.h>
int main()
{
	long long int f,b,fd,bd,t,x,y,z,n,ans,p;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld%lld%lld%lld%lld",&f,&b,&t,&fd,&bd);
		if(fd<=f)
		{
			ans=fd*t;
			printf("%lld F\n",ans);
		}
		else
		{
			if(f==b)
			{
				ans=0;
				printf("No Ditch\n");
			}
			else if(f>b)
			{
				x=fd-f;
				y=x/(f-b);
				z=x%(f-b);
				if(z!=0)
				y++;
				
				ans=(y*(f+b)*t) + (fd-(y*(f-b)))*t ;
				printf("%lld F\n",ans);
			}
			else if(b>f)
			{
				//p=b-f;
				x=bd;
				y=x/(b-f);
				z=x%(b-f);
				
				ans=(y*(f+b)*t) ;
				if(z!=0)
				{
					ans+= (f+b-(b-f-z))*t;
				}
				printf("%lld B\n",ans);
			}
		}
	}
	return 0;
}
