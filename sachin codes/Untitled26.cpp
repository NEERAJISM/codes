#include<bits/stdc++.h>
using namespace std;
char s[100003];
int n,type;

int func1(char s1[])
{
	//cout<<"func3"<<endl;
	int i,j,ans=0,pos;
	for(i=0;i<n;i++)
	{
		cout<<s1[i];
		if(s1[i]!='B'&&i%2==0)
		{
			for(j=i+1;j<n;j++)
			{
				if(s1[j]=='B')
				{
					s1[j]='G';  s1[i]='B';   pos=j;
					break;
				}
			}
			ans+=pow((abs(pos-i)),type);
		}
		if(s1[i]!='G'&&i%2!=0)
		{
			for(j=i+1;j<n;j++)
			{
				if(s1[j]=='G')
				{
					s1[j]='B';  s1[i]='G';   pos=j;
					break;
				}
			}
			ans+=pow((abs(pos-i)),type);
		}
		cout<<"i="<<i<<"ans="<<ans<<endl;
	}
	return ans;
}
int func2(char s2[])
{
	int i,j,ans=0,pos;
	for(i=0;i<n;i++)
	{//cout<<s2[i];
		if(s2[i]!='G'&&i%2==0)
		{
			for(j=i+1;j<n;j++)
			{
				if(s2[j]=='G')
				{
					s2[j]='B';  s2[i]='G';   pos=j;
					break;
				}
			}
			ans+=pow((abs(pos-i)),type);
		}
		if(s2[i]!='B'&&i%2!=0)
		{
			for(j=i+1;j<n;j++)
			{
				if(s2[j]=='B')
				{
					s2[j]='G';  s2[i]='B';   pos=j;
					break;
				}
			}
			ans+=pow((abs(pos-i)),type);
		}//cout<<"i="<<i<<"ans="<<an<<endl;
	}
	return ans;
}
int func3(char s1[])
{
	//cout<<"func3"<<endl;
	int i,j,ans=0,pos;
	for(i=0;i<n;i++)
	{
		//cout<<s1[i];
		if(s1[i]!='B'&&i%2==0)
		{
			for(j=i+1;j<n;j++)
			{
				if(s1[j]=='B')
				{
					s1[j]='G';  s1[i]='B';   pos=j;
					break;
				}
			}
			ans+=2*(abs(pos-i))-1;
		}
		if(s1[i]!='G'&&i%2!=0)
		{
			for(j=i+1;j<n;j++)
			{
				if(s1[j]=='G')
				{
					s1[j]='B';  s1[i]='G';   pos=j;
					break;
				}
			}
			ans+=2*(abs(pos-i))-1;
		}
		//cout<<"i="<<i<<"ans="<<ans<<endl;
	}
	return ans;
}
int func4(char s2[])
{
	int i,j,an=0,pos;
	for(i=0;i<n;i++)
	{//cout<<s2[i];
		if(s2[i]!='G'&&i%2==0)
		{
			for(j=i+1;j<n;j++)
			{
				if(s2[j]=='G')
				{
					s2[j]='B';  s2[i]='G';   pos=j;
					break;
				}
			}
			an+=2*(abs(pos-i))-1;
		}
		if(s2[i]!='B'&&i%2!=0)
		{
			for(j=i+1;j<n;j++)
			{
				if(s2[j]=='B')
				{
					s2[j]='G';  s2[i]='B';   pos=j;
					break;
				}
			}
			an+=2*(abs(pos-i))-1;
		}//cout<<"i="<<i<<"ans="<<an<<endl;
	}
	return an;
}

int main()
{
	int t,i,x,y,z,c1,c2,c3,c4;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&type);
		cin>>s;
		n=strlen(s);
		x=0;y=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='B')
			x++;
			else
			y++;
		}
		if(abs(x-y)>1)
		printf("-1\n");
		else
		{
			if(type!=2)
			{
				if(x>y)
				{
					int coun=func1(s);
					printf("%d\n",coun);
				}
				else if(x<y)
				{
					int co=func2(s);
					printf("%d\n",co);
				}
				else if(x==y)
				{
					char s1[100002];
		    		for(i=0;i<n;i++)
		    		s1[i]=s[i];
		    		int c1=func3(s);
		    		int c2=func4(s1);
		    		int c=min(c1,c2);
					printf("%d\n",c);
				}
		    }
		    else if(type==2)
		    {
		    	if(x>y)
		    	{
		    		int c=func3(s);
		    		printf("%d\n",c);
		    	}
		    	else if(x<y)
		    	{
		    		int c=func4(s);
		    		printf("%d\n",c);
		    	}
		    	else
		    	{
		    		char s1[100002];
		    		for(i=0;i<n;i++)
		    		s1[i]=s[i];
		    		int c1=func3(s);
		    		int c2=func4(s1);
		    		int c=min(c1,c2);
					printf("%d\n",c);
		    	}
		    }
			
		}
	}
	return 0;
}
