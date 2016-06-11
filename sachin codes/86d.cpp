#include<bits/stdc++.h>
using namespace std;

#define BLOCK 448

int a[200003];
long long int ans=0;



struct que
{
	int first,second,third;
};

que query[200003];

long long int res[200003];
long long int hash[1000004];

bool cmp(que x, que y) {
	if(x.first/BLOCK != y.first/BLOCK) {
		return x.first/BLOCK < y.first/BLOCK;
	}
	return x.second< y.second;
}

void add(int position)
{
	long long int num=(long long int)(a[position]);
	hash[num]++;
	
	{
		ans=ans-((hash[num]-1)*(hash[num]-1)*num);
		ans=ans+(hash[num]*hash[num]*num);
	}
}
void remov(int position)
{
	long long int num=(long long int)(a[position]);
	//if(hash[num]!=0)
	hash[num]--;

	{
		ans=ans-((hash[num]+1)*(hash[num]+1)*num);
		ans=ans+(hash[num]*hash[num]*num);
	}
}

int main()
{
	int n,i,q,x,y,L,R,pos,temp;
	//cin>>n>>q;
	scanf("%d%d",&n,&q);
	//read(n);
	//read(q);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		//read(temp);
		//a[i]=temp;
	}
	//scanf("%d",&a[i]);
	//cin>>a[i];
	//
	//scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		//cin>>x>>y;
		scanf("%d%d",&x,&y);
		//read(x);
		//read(y);
		x--;y--;
		query[i].first=x;
		query[i].second=y;
		query[i].third=i;
	}
	sort(query,query+q,cmp);
	
	int currL=-1,currR=-1;
	for(i=0;i<q;i++)
	{
		//cout<<" query"<<i<<"  ";
		L=query[i].first;   R=query[i].second;  pos=query[i].third;
		while(L<currL)
		{
			add(currL-1);
			currL--;
			//cout<<ans<<" ";
		}
		while(L>currL)
		{
			remov(currL);
			currL++;
			//cout<<ans<<" ";
		}
		while(R<currR)
		{
			remov(currR);
			currR--;
			//cout<<ans<<" ";
		}
		while(R>currR)
		{
			add(currR+1);
			currR++;
			//cout<<ans<<" ";
		}
		res[pos]=ans;
	}
	for(i=0;i<q;i++)
	{
		printf("%I64d\n",res[i]);
		//cout<<res[i]<<endl;
		//temp2=res[i];
		//write(temp2);
	}
	return 0;
}
