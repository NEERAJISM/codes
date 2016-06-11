#include<bits/stdc++.h>
using namespace std;

char c[1000],ch;
int main()
{
	int t,n,i,j,pos;
	double n1,n2,n3,ans;
	scanf("%d\n",&t);
	while(t--)
	{
		gets(c);	
		n1=0; n2=0; n3=0; i=0;
		
		if(c[i]!='x')
		{
			if(c[i]!='-')
			{//cout<<c[i+1];
				while(isdigit(c[i]))//c[i]!='+'||c[i]!='-'||c[i]!='*'||c[i]!='/'||c[i]!=' '
				{
					//cout<<c[i];
					n1=(n1*10)+(c[i]-'0');
					i++;
				}
				//cout<<"n1="<<n1<<endl;
			}
			else if(c[i]=='-')
			{
				i++;
				while(isdigit(c[i]))
				{
					n1=(n1*10)+(c[i]-'0');
					i++;
				}
				n1=-n1;
			}
			
			if(c[i]==' ')
			{ 
			    i++;
			}
				pos=i;  i++;
				if(c[i]!='x')
				{
					if(c[i]=='-')
					{
						i++;
						while(isdigit(c[i]))
						{
							n2=(n2*10)+(c[i]-'0');
							i++;
						}
						n2=-n2;
					}
					else if(c[i]!='-')
					{
						while(isdigit(c[i]))
						{
							n2=(n2*10)+(c[i]-'0');
							i++;
						}
					}
					
					//cout<<"n2="<<n2<<endl;
					if(c[pos]=='+')
					ans=n1+n2;
					else if(c[pos]=='-')
					ans=n1-n2;
					else if(c[pos]=='*')
					ans=n1*n2;
					else if(c[pos]=='/')
					ans=n1/n2;
					
					printf("%.6lf\n",ans);
				}
				else if(c[i]=='x')
				{
					i++;
					while(isdigit(c[i]))
					{
						i++;
					}
					if(c[i]=='-')
					{
						i++;
						while(isdigit(c[i]))
						{
							n3=(n3*10)+(c[i]-'0');
							i++;
						}
						n3=-n3;
					}
					//cout<<"n3="<<n3	 <<endl;
					else if(c[i]!='-')
					{
						i++;
						while(isdigit(c[i]))
						{
							n3=(n3*10)+(c[i]-'0');
							i++;
						}
					}
					
					if(c[pos]=='+')
					ans=n3-n1;
					else if(c[pos]=='-')
					ans=n3+n1;
					else if(c[pos]=='*')
					ans=n3/n1;
					else if(c[pos]=='/')
					ans=n1/n3;
					
					printf("%0.6lf\n",ans);
					//cout<<ans;
				}
				
			
		}
		else if(c[0]=='x')
		{
			i=1;
			if(c[i]==' ')
			i++;
			
			pos=i;
			
			i++;
			
			if(c[i]=='-')
			{
				i++;
				while(isdigit(c[i]))
				{
					n2=(n2*10)+(c[i]-'0');
					i++;
				}
				n2=-n2;
			}
			else if(c[i]!='-')
			{
				while(isdigit(c[i]))
				{
					n2=(n2*10)+(c[i]-'0');
					i++;
				}
			}
			
					while(c[i]==' '||c[i]=='=')
					{
						i++;
					}
					if(c[i]=='-')
					{
						i++;
						while(isdigit(c[i]))
						{
							n3=(n3*10)+(c[i]-'0');
							i++;
						}
						n3=-n3;
					}
					else if(c[i]!='-')
					{
						i++;
						while(isdigit(c[i]))
						{
							n3=(n3*10)+(c[i]-'0');
							i++;
						}
					}
					
					if(c[pos]=='+')
					ans=n3-n2;
					else if(c[pos]=='-')
					ans=n3+n2;
					else if(c[pos]=='*')
					ans=n3/n2;
					else if(c[pos]=='/')
					ans=n2*n3;
					
					printf("%0.6lf\n",ans);
		}
		
	}
	return 0;
}
