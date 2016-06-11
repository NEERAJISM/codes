#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
 
int premin[25][10000002];
long long int array[10000002];
 
 
void premin_process(int n,int k){
	int i,j;
	for(i=0;i<n;i++)
		premin[0][i]=i;
	for(j=1;1<<(j-1) <=k ;j++){
		for(i=0;i+(1<<(j-1))<n;i++){
			if(array[premin[j-1][i]]<=array[premin[j-1][i+(1<<(j-1))]])
				premin[j][i]=premin[j-1][i];
			else
				premin[j][i]=premin[j-1][i+(1<<(j-1))];
		}
	}
}
 
 
int query_min(int start,int end){
	int diff=end-start;
	diff=31-__builtin_clz(diff+1);
    //diff=log(diff)/log(2);
	if(array[premin[diff][start]]<=array[premin[diff][end-(1<<diff)+1]])
		return array[premin[diff][start]];
	return array[premin[diff][end-(1<<diff)+1]];
}
 
 
int main()
{
	int n,k,q;
	int a,b,c,d,e,f,r,s,t,m,A1,range_min,xx1,yy1;
	long long int l1,d1;
	int L,R,x,i,xx,yy,lc,lm,la,dc,dm,da;
	long long int sum=0,prod=1,pq;
	
	//scanf("%d%d%d",&n,&k,&q);
	//scanf("%d%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&A1);
	//scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&l1,&la,&lc,&lm,&d1,&da,&dc,&dm);
	cin>>n>>k>>q;
	cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>A1;
	cin>>l1>>la>>lc>>lm>>d1>>da>>dc>>dm;
	
	array[0]=A1;
	int kk=k;
	pq=t;
	for(x=1;x<n;x++)
	{
		if(pq*t>=s)
		pq=(pq*t)%s;
		else
		pq=pq*t;
		if(pq<=r) 
	    {
			if(array[x-1]*array[x-1]>=m)
			xx1=(array[x-1]*array[x-1])%m;
			else
			xx1=array[x-1]*array[x-1];
			
			if(xx1*a>=m)
			xx1=(xx1*a)%m;
			else
			xx1=(xx1*a);
			
			if(b*array[x-1]>=m)
			yy1=(b*array[x-1])%m;
			else
			yy1=b*array[x-1];
			
			if(xx1+yy1+c>=m)
			array[x]=((xx1+yy1+c)%m);
			else
			array[x]=(xx1+yy1+c);
		}                        
		else                                         															//		else
		{
			if(array[x-1]*array[x-1]>=m)
			xx1=(array[x-1]*array[x-1])%m;
			else
			xx1=array[x-1]*array[x-1];
			
			if(xx1*d>=m)
			xx1=(xx1*d)%m;
			else
			xx1=(xx1*d);
			
			if(e*array[x-1]>=m)
			yy1=(e*array[x-1])%m;
			else
			yy1=e*array[x-1];
			
			if(xx1+yy1+f>=m)
			array[x]=((xx1+yy1+f)%m);
			else
			array[x]=(xx1+yy1+f);
		}
	}
 //for(i=0;i<n;i++)
 //cout<<array[i]<<" ";
	
	premin_process(n,kk);
	
	for(i=1;i<=q;i++)  
	{
		if(la*l1>=lm)
		xx=(la*l1)%lm;
		else
		xx=la*l1;
		if(xx+lc>=lm)
		l1=(xx+lc)%lm;
		else
		l1=xx+lc;
	
		if(da*d1>=dm)
		yy=(da*d1)%dm;
		else
		yy=da*d1;
		if(yy+dc>=dm)
		d1=(yy+dc)%dm;
		else
		d1=yy+dc;
		 
		L=l1+1;											                     
		R=min((int)(L+k-1+d1),n);											         
		
		range_min = query_min(L-1,R-1);
		sum=(sum+range_min);
		
		if(prod*range_min>=M)
		prod=(prod*range_min)%M;
		else
		prod=prod*range_min;
	}
	cout<<sum<<" "<<prod<<endl;
	//printf("%lld %lld\n",sum,prod);
	return 0;
}   
