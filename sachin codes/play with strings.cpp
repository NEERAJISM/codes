#include<bits/stdc++.h>
using namespace std;

long long int powe[100003];

void calc()
{
	powe[0]=1;
	for(int i=1;i<=100002;i++)
	{
		powe[i]=(powe[i-1]*10+1)%1000000007;
	}
}

void multiply(long long int F[2][2], long long int M[2][2]);
 
void power(long long int F[2][2], long long int n);

/* function that returns nth Fibonacci number */
long long int fibonacci(long long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 void power(long long int F[2][2], long long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(long long int F[2][2], long long int M[2][2])
{
  long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x%1000000007;
  F[0][1] = y%1000000007;
  F[1][0] = z%1000000007;
  F[1][1] = w%1000000007;
}

int main()
{
	int i,t,nn,j;
	long long int sum,ans;
	calc();
	char s[100004];
//	for(i=0;i<5;i++)
//	cout<<power[i]<<" ";
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&nn);
		cin>>s;
		
		sum=0;
		for(i=nn-1;i>=0;i--)
		{
			int x=(int)(s[i]-'0');  //cout<<"x="<<x<<endl;
			j=(nn-i-1);
			sum=(sum+((x*(nn-j)%1000000007)*powe[j])%1000000007)%1000000007;  //cout<<"sum="<<sum<<endl;
		}
		
		ans=fibonacci(sum);
		printf("%lld\n",ans);
	}
	return 0;
}
