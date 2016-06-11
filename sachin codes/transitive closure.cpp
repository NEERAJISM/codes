#include<bits/stdc++.h>
using namespace std;

int a[10][10];
int t[10][10];

int main()
{
	int n,i,j;
	cin>>n;
	
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	cin>>a[i][j];
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j])
			t[i][j]=1;
			else
			t[i][j]=0;
		}
	}
	
	for(int k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				t[i][j]=( t[i][j] | (t[i][k] & t[k][j]) );
			}
		}
	}
	
	
	cout<<"transitive closure\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<t[i][j]<<"  ";
		}
		cout<<endl;
	}

	
	return 0;
}
