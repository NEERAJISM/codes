#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector <int> a;
	int j,n;
	vector <int> ::iterator i;
	for(j=0;j<5;j++)
	{
		cin>>n;
		a.push_back(n);
	}
	
	sort(a.begin(),a.end());
		cout<<"sorted sequence is ";
	for(j=0;j<5;j++)
	{
	cout<<a[j]<<"\t";
	}
	return 0;
	
}
