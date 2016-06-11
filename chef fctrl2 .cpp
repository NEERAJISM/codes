#include <bits/stdc++.h>
using namespace std;

void factorial(int n)
{
	int i,carry,base,size = 1,j,total;
	vector<int> v(100000,0);
	v[0]=1;

	for(i=2;i<=n;i++)
	{
		carry = 0;
		for(j=0;j<size;j++)
		{
			total=v[j]*i + carry;
			v[j] = total%10;
			carry = total / 10;
		}

		while(carry !=0)
		{
			size++;
			total = carry;
			v[size-1] = total%10;
			carry = carry/10;
		}
	}

	for(i=size-1;i>=0;i--)
		cout<<v[i];

	v.clear();
	cout<<endl;

}

int main()
{
	int t,n;
	cin>>t;

	while(t--)
	{
		cin>>n;

		if(n==0)
			cout<<"0"<<endl;
        else
		    factorial(n);
	}
	return 0;
}
