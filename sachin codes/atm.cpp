#include<iostream>
using namespace std;
int main()
{
	int a;
	float n,o;
	cin>>a>>n;
	if(a>(n-0.5)||a%5!=0)
	{
		cout<<n<<endl;
		
	}
	else
	{
		float b=n-(a+0.5);
		cout<<b<<endl;
		
	}
	return 0;
}
