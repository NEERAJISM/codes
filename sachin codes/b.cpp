#include<bits/stdc++.h>
using namespace std;

int a[4][100003];
int arr[62][10001],power[64],N;

int gcd(int a,int b){
if(b>a)return gcd(b,a);
return b==0?a:gcd(b,a%b);
}

int solve(int i,int curgcd)
{
	if(i==N)			//last element and before it all elements are left; there are no more elements
	{
		if(curgcd==1)
			return 1;
		else 
			return 0;
	}
	if(arr[i][curgcd]!=-1)
		return arr[i][curgcd];
	if(curgcd==1)
		arr[i][curgcd]=power[N-i];//2^(n-i) :: all subsequent calls return 1 (for faster soln)
	else
		arr[i][curgcd]=solve(i+1,gcd(curgcd,a[3][i]))+solve(i+1,curgcd);//take ith eleement + dont take ith element
	return arr[i][curgcd];
}

int func()
{
	int i;
		power[0]=1;
	for(i=1;i<62;i++)
	power[i]=2*power[i-1];
	
			int k=0;
		memset(arr,-1,sizeof(arr));
		for(i=0;i<N;i++)
		k+=solve(i+1,a[3][i]);	
		return k;
}

int main()
{
	int n,i,q,u,v,w,pos,val,ans;
	scanf("%d",&n);
	N=n-1;
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		a[1][i]=u;     a[2][i]=v;    a[3][i]=w;
	}
	ans=func();
	printf("%d\n",ans);
	
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&pos,&val);
		a[3][pos-1]=val;
		ans=func();
		printf("%d\n",ans);
	}
	return 0;
}
