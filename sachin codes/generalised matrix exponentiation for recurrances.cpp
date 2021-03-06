#include<iostream>
#include<stdio.h>
#define MOD 1000000007
using namespace std;

void matmult(long long  a[][2],long long  b[][2],long long c[][2])//multiply matrix a and b. put result in c
{
    int i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=0;
            for(k=0;k<2;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
                c[i][j]=c[i][j]%MOD;
            }
        }
    }
 
}
void matpow(long long Z[][2],long long int n,long long ans[][2])
//find ( Z^n )% M and return result in ans
{
 
    long long temp[2][2];
    //assign ans= the identity matrix
    ans[0][0]=1;
    ans[1][0]=0;
    ans[0][1]=0;
    ans[1][1]=1;
    int i,j;
    while(n>0)
    {
        if(n&1)
        {
            matmult(ans,Z,temp);
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    ans[i][j]=temp[i][j];
        }
        matmult(Z,Z,temp);
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                Z[i][j]=temp[i][j];
 
 
        n=n/2;
    }
    return;
     
}
long long int question(long long int n)
{
	long long int Z[2][2]={{1,1},{1,0}};
	long long int res[2][2];
	long long int F[2][1]={{1},{0}};
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	else if(n==2)
	return 1;
	else if(n>=3)
	{
		matpow(Z,n-1,res);
		long long int fib=((1*res[0][0])+(0*res[0][1]))%MOD;                                 //matmult(res1,F,res2);
		return fib;
	}
	
}
int main()
{
  long long int n;
  cout<<"enter the number\n";
  cin>>n;
  cout<<"nth fibonacci number is = "<<question(n)<<endl;
  return 0;
}
