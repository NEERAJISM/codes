#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int a[1000000];
int main()
{
	int i,n;
	//cout<<"enter the size\n";
	scanf("%d",&n);
	//cout<<"enter the array\n";
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++)
{
	printf("%d",a[i]);
	printf("\n");}
	
}
