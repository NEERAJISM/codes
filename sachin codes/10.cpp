#include<iostream>
#include<vector>
using namespace std;
int main()
{
	long int n;
	int m;
	cin>>n>>m;
	vector <double> a(n+1);
	long int b,c,i;
	double k;
	while(m--)
	{
		cin>>b>>c>>k;
		k=k/10000;
		for(i=b;i<=c;i++)
		{
			a[i]+=k;
		}
	}
	double max=a[1];
		for(i=1;i<=n;i++)
		{
			if(a[i]>=max)
			{
				max=a[i];
			}
			
		}
		
		cout<<max*10000;
		return 0;
	
	
}
