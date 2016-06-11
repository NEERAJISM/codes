#include<iostream>
using namespace std;
int main()
{
long int i,n,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		if(k%2==0)
		cout<<((k/2)*(k/2))<<endl;
		else
		cout<<(((k/2)*(k/2))+(k/2))<<endl;
	}
	return 0;
}
