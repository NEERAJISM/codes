#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,k,i,c1,c2,count,count2,stack,prev,ans,x,y,j,K;
	char s[100003];
	int b[100003],a[100003];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&K);
		cin>>s;
		
		if(K==1)
		{
			int p1=0,p2=0;
			for(i=0;i<n;i++)
			{
				if(i%2==0)
				{
					if(s[i]!='0')
					p1++;
				}
				else
				{
					if(s[i]!='1')
					p1++;
				}
			}
			//cout<<"p1="<<p1<<endl;
			for(i=0;i<n;i++)
			{
				if(i%2!=0)
				{
					if(s[i]!='0')
					p2++;
				}
				else
				{
					if(s[i]!='1')
					p2++;
				}
			}
			//cout<<"p2="<<p2<<endl;
			if(p1<p2)
			{
				printf("%d\n",p1);
				for(i=0;i<n;i++)
				if(i%2==0)
				cout<<0;
				else
				cout<<1;
				
				cout<<endl;
			}
			else
			{
				printf("%d\n",p2);
				for(i=0;i<n;i++)
				if(i%2!=0)
				cout<<0;
				else
				cout<<1;
				
				cout<<endl;
			}
		}
		else{
		
		k=0;c1=0;c2=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				c1++;
				if(c2!=0)
				{
					a[k++]=c2;
					c2=0;
				}
			}
			else
			{
				c2++;
				if(c1!=0)
				{
					a[k++]=c1;
					c1=0;
				}
			}
		}
		if(c1!=0)
		a[k++]=c1;
		else
		a[k++]=c2;
		
		//for(i=0;i<k;i++)
	//	cout<<a[i]<<"  ";
		
		if(s[0]=='0')
		prev=1;
		else
		prev=0;
		
		ans=0;stack=0;
		for(i=0;i<k;i++)
		{
			if(a[i]>K)
			{
				x=a[i]/(K+1);    y=a[i]%(K+1);
				ans+=x;
				//cout<<ans<<" ";
				if(y!=0)
				{
					count=0;
					for(j=0;j<a[i];j++)
					{
						if(count==K)
						{
							if(prev==1)
							b[stack++]=1;
							else
							b[stack++]=0;
							count=0;
						}
						else
						{
							if(prev==1)
							b[stack++]=0;
							else
							b[stack++]=1;
							
							count++;
						}
					}
				}
				else
				{
					for(j=0;j<K-1;j++)
					{
						if(prev==1)
						b[stack++]=0;
						else
						b[stack++]=1;
					}
					if(prev==1)
					b[stack++]=1;
					else
					b[stack++]=0;
					
					a[i]=a[i]-K;    count=0;
					for(j=0;j<a[i];j++)
					{
						if(count==K)
						{
							if(prev==1)
							b[stack++]=1;
							else
							b[stack++]=0;
							count=0;
						}
						else
						{
							if(prev==1)
							b[stack++]=0;
							else
							b[stack++]=1;
							
							count++;
						}
					}
				}
				if(prev==1)
				prev=0;
				else
				prev=1;
			}
			else{
				for(j=0;j<a[i];j++)
				{
					if(prev==1)
					b[stack++]=0;
					else
					b[stack++]=1;
				}
				if(prev==1)
				prev=0;
				else
				prev=1;
			}
		}
		printf("%d\n",ans);
		for(i=0;i<stack;i++)
		printf("%d",b[i]);
		cout<<endl;
	  }
	}
	return 0;
}
