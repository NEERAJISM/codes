#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,a,b,c,i;
	while(1)
	{
		cin>>a>>b>>c;
		if(a==0&&b==0&&c==0)
		break;
		
		if(2*b==(a+c))
		{
			cout<<"AP "<<c+(b-a)<<endl;
		}
		else
		{
			cout<<"GP "<<(c*b)/a<<endl;
		}
	}
	return 0;
}
