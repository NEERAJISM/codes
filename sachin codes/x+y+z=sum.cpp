#include<bits/stdc++.h>
using namespace std;
int a[78];
int main()
{
	int i,j,k,n,sum,flag=0;
	cout<<"enter size\n";
	cin>>n;
	cout<<"enter elements\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<"enter sum\n";
	cin>>sum;
	
	sort(a,a+n);
	
	for(i=0;i<=n-2;i++)
	{
		j=i+1;  k=n-1;
		while(j<k)
		{
			if(a[i]+a[j]+a[k]==sum)
			{
				cout<<a[i]<<"  "<<a[j]<<"  "<<a[k]<<endl;
				flag=1;
				break;
			}
			else if(a[i]+a[j]+a[k]<sum)
			j++;
			else
			k--;
		}
		if(flag)
		break;
	}
	if(!flag)
	cout<<"not found";
	return 0;
}
