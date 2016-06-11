#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    long long int n,i,s1=0;
	scanf("%lld",&n);
    s1=n%6;
    if(s1==0||s1==1||s1==3)
	printf("yes\n");
    else
	printf("no\n");
	return 0;
}
