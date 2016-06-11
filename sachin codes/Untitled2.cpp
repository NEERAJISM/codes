#include<bits/stdc++.h>
using namespace std;

int F[2][2]={{1,1},{1,0}};
int Y[2][2]={{1,1},{1,0}};
int X[2][2]={{1,0},{0,1}};

void multiply1()
{
	int x =  X[0][0]*Y[0][0] + X[0][1]*Y[1][0];
  	int y =  X[0][0]*Y[0][1] + X[0][1]*Y[1][1];
  	int z =  X[1][0]*Y[0][0] + X[1][1]*Y[1][0];
  	int w =  X[1][0]*Y[0][1] + X[1][1]*Y[1][1];
 
  X[0][0] = x;
  X[0][1] = y;
  X[1][0] = z;
  X[1][1] = w;
}

void multiply2()
{
	int x =  Y[0][0]*Y[0][0] + Y[0][1]*Y[1][0];
  	int y =  Y[0][0]*Y[0][1] + Y[0][1]*Y[1][1];
  	int z =  Y[1][0]*Y[0][0] + Y[1][1]*Y[1][0];
  	int w =  Y[1][0]*Y[0][1] + Y[1][1]*Y[1][1];
 
  Y[0][0] = x;
  Y[0][1] = y;
  Y[1][0] = z;
  Y[1][1] = w;
}

int powerr(int n)
{
	while(n>0)
	{
		if(n%2==1)
		{
			multiply1();  // x=x*y;
		}
		multiply2();   // y=y*y;
		n=n/2;
	}
}

int main()
{
	int n;
	cin>>n;
	if(n==0)
	cout<<"0";
	else if(n==1)
	cout<<"1";
	else
	{
		powerr(n-1);
		cout<<X[0][0]<<endl;
	}
	return 0;
	
}
