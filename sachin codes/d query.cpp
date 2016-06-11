#include<bits/stdc++.h>
using namespace std;

#define BLOCK 555

int a[30005],ans=0;

struct que
{
	int first,second,third;
};

que query[200003];

int res[200003];
int hash[1000004];

bool cmp(que x, que y) {
	if(x.first/BLOCK != y.first/BLOCK) {
		return x.first/BLOCK < y.first/BLOCK;
	}
	return x.second< y.second;
}

void add(int position)
{
	int num=a[position];
	hash[num]++;
	if(hash[num]==1)
	ans++;
}
void remov(int position)
{
	int num=a[position];
	hash[num]--;
	if(hash[num]==0)
	ans--;
}

int main()
{
	int n,i,q,x,y,L,R,pos;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&x,&y);
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
		printf("%d\n",res[i]);
	}
	return 0;
}
