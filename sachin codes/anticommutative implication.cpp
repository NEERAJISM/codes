#include<bits/stdc++.h>
using namespace std;
 
int a[1002][1002];
vector<vector<int> > g;
int visited[1002];
int ans[1002];
int res[1002];
int sd=73,X,Y,Z,T,W;
 
void random_seed(int S)
{
	X=S;
  Y = X * S;
  Z = Y * S;
  W = Z * S;
}
 
int random_number()
{	 
	T = X ^ (X << 11);
  X = Y; Y = Z; Z = W;                       
  return W = abs((W ^ (W >> 19)) ^ (T ^ (T >> 8))); 
}
 
void make_zero(int arr[],int n)
{
	for(int i=1;i<=n;i++)
	arr[i]=0;
}
 
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start]=1;
	random_seed(sd++);
	ans[start]=random_number()%2;
	
	while(!(q.empty()))
	{                                
		int curr_ver=q.front();
		q.pop();
		for(int i=0;i<g[curr_ver].size();i++)
		{
			int curr_neigh=g[curr_ver][i];
			if(!visited[curr_neigh])
			{
				visited[curr_neigh]=1;
				q.push(curr_neigh);
				if(ans[curr_ver])
				ans[curr_neigh]=0;
				else
				ans[curr_neigh]=1;
			}
		}
	}
}
 
void function(int n,int c1)
{
	int i,ii,j,count,max=-1,val;
	
	for(ii=1;ii<=1100;ii++)
	{
		make_zero(ans,n);
		make_zero(visited,n);
		
		for(i=1;i<=n;i++)
		{
			if(g[i].size()&&visited[i]==0)
			{
				bfs(i);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(visited[i]==0&&g[i].size()==0)
			{
				random_seed(sd++);
				ans[i]=random_number()%2;
				//cout<<"i="<<i<<endl;
			}
		}
		count=0;
		for(i=1;i<=n;i++)
		{
			if(ans[i]==0)
			{//cout<<"klsdlfl";
				count++;
			}
		}
		val=2*count*(n-count);
		val=val-c1;
		//cout<<"val="<<val<<endl;
		if(val>max)
		{
			max=val;
			for(i=1;i<=n;i++)
			res[i]=ans[i];
		}
	}
}
void sachin_ism(int n)
{
	int ANS=-1, save_cnt=-1;
        bool ok=true;
        for(int k=0;k<=(1<<n);k++){
            int cnt=0;
            ok=true;
            for(int i=1;i<=n;i++){

                for(int j=1;j<=n;j++){

                    bool xor_val=((k & (1<<i-1))>0) ^ ((k & (1<<j-1))>0);
                    if(a[i][j]==1 && xor_val==0){

                        ok=false;
                        break;
                    }
                    if(a[i][j]==0 && xor_val==1){

                        cnt++;
                    }
                }
                if(!ok){
                    break;
                }
            }
            if(ok){

                if(cnt>=save_cnt){

                    ANS=k;
                    save_cnt=cnt;
                }
            }
        }
        //cout<<ans<<endl;
        if(ANS!=-1){

            for(int i=0;i<n;i++){

                if(ANS & (1<<i)){

                    printf("1 ");
                }
                else{

                    printf("0 ");
                }
            }
        }
        else{

            printf("-1");
        }
        printf("\n");
}

 
int main()
{
	int t,i,j,flag,n,p,c;
	scanf("%d",&t);
	while(t--)
	{
		sd=73;
		scanf("%d",&n);   flag=0;
		g.clear();
		g.resize(n+2);
		int hash[n+2];
		make_zero(hash,n);
		make_zero(res,n);
		 
		 c=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]==1)
				c++;
				if(i==j&&a[i][j]==1)
				flag=1;
			}
		}
		if(n<=10)
		{
			sachin_ism(n);
		}
		else{
		
		if(flag==1)
		{
			printf("-1\n");
		}
		else
		{
			int flag2=0;
			
			for(i=1;i<=n;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					if(a[i][j]==1)
					{
						for(p=0;p<g[i].size();p++)
						hash[g[i][p]]++;
						
						for(p=0;p<g[j].size();p++)
						{
							if(hash[g[j][p]])
							{
								flag2=1;
								break;
							}
						}
						
						if(flag2==0)
						{
							g[i].push_back(j);
							g[j].push_back(i);
						}
						
						make_zero(hash,n);
					}
					if(flag2==1)
					break;
				}
				if(flag2==1)
				break;
			}
			if(flag2==1)
			printf("-1\n");
			else
			{
					function(n,c);
					for(i=1;i<=n;i++)
					printf("%d ",res[i]);
					printf("\n");
				
			}
		
		}
	}
	}
	return 0;
}  
