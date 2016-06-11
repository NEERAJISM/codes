#include<iostream>
#include<stdio.h>
using namespace std;
int a[100001][100001];
int main()
{
	int n,d,m,i,j;
	for(i=1;i<100001;i++)
	{
		for(j=1;j<100001;j++)
		{
			a[i][j]=-1;
		}
	}
	return 0;
}
