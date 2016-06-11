#include<bits/stdc++.h>
using namespace std;
int a[100003],b[100003],c[100003],d[100003],n,k;

void function()
{
	int c1=0,c2=0;
	b[0]=0;   c[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		c1++;
		else
		c2++;
		b[i]=c1;
		c[i]=c2;
		//cout<<c1<<"  "<<c2<<endl;
	}
}

void counting(int l,int r)
{
	int y=l-1,count=0,co=0,x,p=0;
	for(int j=l;j<=r;j++)
	{
		x=j-y;          //cout<<"x="<<x<<endl;
			if(b[j]-b[y]<=k&&c[j]-c[y]<=k)
			{
				count=(x*(x+1))/2;  
			}
			if(b[j]-b[y]==k||c[j]-c[y]==k)
			{
				y=j;           p++;
				co+=count;
			}
			//cout<<"count="<<count<<"co="<<co<<endl;
			if(y==j)
			d[j]=co+((p-1)*k*(k-1)/2);
			else
			d[j]=co+count+((p)*k*(k-1)/2);
	}

}

int main()
{
	int t,q,i,j,l,r,ans;
	char s[100003];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&q);
		cin>>s;
		for(i=0;i<n;i++)
		a[i+1]=s[i]-'0';
		function();
		counting(1,n);
		for(i=0;i<=n;i++)
		cout<<d[i]<<"  "<<endl;
		while(q--)
		{
			scanf("%d%d",&l,&r);
			
			printf("%d\n",ans);
		}
	}
	return 0;
}
