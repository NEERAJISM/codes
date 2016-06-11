#include<iostream>
#include<string.h>
using namespace std;


int a[1000][1000];

int lcs(char s[],char t[],int n,int m)
{
	int i,j;
	for(i=0;i<=n;i++)
	a[i][m]=0;
	for(j=0;j<=m;j++)
	a[n][j]=0;
	for(i=n-1;i>=0;i--)
	{
		for(j=m-1;j>=0;j--)
		{
			a[i][j]=a[i+1][j+1];
			
			if(s[i]==t[j])
			a[i][j]++;
			
			if(a[i][j]<a[i][j+1])
			a[i][j]=a[i][j+1];
			
			if(a[i][j]>a[i+1][j])
			a[i][j]=a[i+1][j];
		}
	}
	return a[0][0];
}

int main()
{
	char s[1000],t[1000];
	cout<<"enter the strings\n";
	cin>>s>>t;
	int n=strlen(s);
	int m=strlen(t);
	int max=lcs(s,t,n,m);
	cout<<"largest common subsequence = "<<max;
	return 0;
}
