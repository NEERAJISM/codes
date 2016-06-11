#include<bits/stdc++.h>
using namespace std;

 
int premin[1000002][26];
int array[1000002];


void premin_process(int n){
	int i,j;
	for(i=0;i<n;i++)
		premin[i][0]=i;
	for(j=1;1<<j <=n ;j++){
		for(i=0;i+(1<<(j-1))<n;i++){
			if(array[premin[i][j-1]]<=array[premin[i+(1<<(j-1))][j-1]])
				premin[i][j]=premin[i][j-1];
			else
				premin[i][j]=premin[i+(1<<(j-1))][j-1];
		}
	}
}

int query_min(int start,int end){
	int diff=end-start;
	diff=31-__builtin_clz(diff+1);
	if(array[premin[start][diff]]<=array[premin[end-(1<<diff)+1][diff]])
		return array[premin[start][diff]];
	return array[premin[end-(1<<diff)+1][diff]];
}

int main()
{
	int n,i,q,x,y,L,R,pos,range_min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	scanf("%d%d",&x,&y);
    premin_process(n);
	range_min = query_min(x-1,y-1);
	cout<<range_min;
	return 0;
}

