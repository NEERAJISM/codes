#include<iostream>
using namespace std;
void print(int x)
{
	int i,j;
	for(j=1;j<=x;j++)
		{
		for(i=25;i>=0;i--)
		cout<<char(97+i);}
}
int main()
{
	char c[10000];
	int i,t,k,a,b;
	cin>>t;
	while(t--)
	{
		cin>>k;
		if(k==0)
		cout<<"a";
		a=k%25;
		b=k/25;
        if(a!=0)
        {
        
		for(i=a;i>=0;i--)
        cout<<char(97+i);
        }	print(b);
        
		cout<<"\n";
	}
	return 0;
}
