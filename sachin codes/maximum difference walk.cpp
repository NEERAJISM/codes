#include<bits/stdc++.h>
using namespace std;

int a[52][52],mark[52][52];

int main()
{
	int n,i,j,kk,x,y,max,u,v,flag,check,dest,special_dest,special_case,max_cost,cost1,cost2,my_score,his_score,mmm,final,maxx;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mark[i][j]=0;
		}
	}
	
	max=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			
			if(i==j)
			mark[i][j]=1;
			
			if(a[i][j]>max)
			{
				max=a[i][j];
				//x=i;  y=j;
			}
		}
	}
					max_cost=-n*(n-1);
					for(kk=1;kk<=n;kk++)
					{
						v=kk;
						for(i=1;i<=n;i++)
						{
							if(mark[v][i]==0)
							{
								cost1=a[v][i];  mmm=0;
								for(j=1;j<=n;j++)
								{
									if(mark[i][j]==0)
									{
										cost2=a[i][j];
										if(cost2>mmm)
										mmm=cost2;
									}
								}
								if(cost1-mmm>max_cost)
								{
									max_cost=cost1-mmm;
									x=v;   y=i;
								}
							}
						}
					}
	//cout<<"x="<<x<<"y="<<y<<endl;
	my_score=0;   his_score=0;
	
	while(1)
	{   
		
		my_score+=a[x][y];
		mark[x][y]=1;
		
		flag=0;
		for(j=1;j<=n;j++)
		{
			if(mark[y][j]==0)
			{
				flag=1;
				break;
			}
		}
		cout<<x<<" "<<y<<endl;
		fflush(stdout);
		
		if(flag)
		{
			cin>>u>>v;
			mark[u][v]=1;
			his_score+=a[u][v];
			
			check=0;
			for(j=1;j<=n;j++)
			{
				if(mark[v][j]==0)
				{
					check=1;
					break;
				}
			}
			if(check)
			{
					max_cost=-n*(n-1);
					for(i=1;i<=n;i++)
					{
						if(mark[v][i]==0)
						{
							cost1=a[v][i];  mmm=0;
							for(j=1;j<=n;j++)
							{
								if(mark[i][j]==0)
								{
									cost2=a[i][j];
									if(cost2>mmm)
									mmm=cost2;
								}
							}
							if(cost1-mmm>max_cost)
							{
								max_cost=cost1-mmm;
								dest=i;
							}
						}
					}//cout<<"dest="<<dest<<endl;
					x=v;  y=dest;
				
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
		if(!check)
		break;
	}
	
	//cout<<"my_score="<<my_score<<endl;
	//cout<<"his_score="<<his_score<<endl;
	return 0;
	
}
