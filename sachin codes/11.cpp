#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,p,i,j,c=0;
	vector <int> a;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>p;
		a.push_back(p);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[j]>=a[i])
			{
				c++;
			}
			else
			break;
		}
	}
	
	cout<<c;
	return 0;
}
