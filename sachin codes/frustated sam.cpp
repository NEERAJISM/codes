#include<iostream>
#include<stdio.h>
#define MOD 1000000007
using namespace std;

long long int A,B;

void matmult(long long  a[][3],long long  b[][3],long long c[][3])//multiply matrix a and b. put result in c
{
    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            c[i][j]=0;
            for(k=0;k<3;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
                c[i][j]=c[i][j]%MOD;
            }
        }
    }
 
}
void matpow(long long Z[][3],long long int n,long long ans[][3])
//find ( Z^n )% M and return result in ans
{
 
    long long temp[3][3];
    //assign ans= the identity matrix
    ans[0][0]=1;ans[0][1]=0;ans[0][2]=0;
    ans[1][0]=0;ans[1][1]=1;ans[1][2]=0;
    ans[2][0]=0;ans[2][1]=0;ans[2][2]=1;
    int i,j;
    while(n>0)
    {
        if(n&1)
        {
            matmult(ans,Z,temp);
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    ans[i][j]=temp[i][j];
        }
        matmult(Z,Z,temp);
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                Z[i][j]=temp[i][j];
 
 
        n=n/2;
    }
    return;
     
}
void question(long long int n,long long int a1,long long int b1,long long int c1,long long int a2,long long int b2,long long int c2)
{
	long long int Z[3][3]={{a1,b1,c1},{a2,b2,c2},{0,0,1}};
	long long int res[3][3];
	long long int F[3][1]={{1},{2},{1}};
	if(n==1)
	{
		A=1;B=2;
	}
	else if(n>=2)
	{
		matpow(Z,n-1,res);
		A=((1*res[0][0])%MOD+(2*res[0][1])%MOD+(1*res[0][2])%MOD)%MOD;                                 //matmult(res1,F,res2);
		B=((1*res[1][0])%MOD+(2*res[1][1])%MOD+(1*res[1][2])%MOD)%MOD; 
	}
	
}
int main()
{
	int t;
	long long int a1,b1,c1,a2,b2,c2,n,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld",&a1,&b1,&c1,&a2,&b2,&c2,&n);
		question(n,a1,b1,c1,a2,b2,c2);
		printf("%lld %lld\n",A,B);
	}
	return 0;
}
