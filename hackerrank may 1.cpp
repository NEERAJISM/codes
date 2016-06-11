#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,l,r,a[100000],out,i;
	vector<long long int> v;
	cin>>t;

	while(t--)
	{
	    v.clear();
		out=0;
		cin>>n>>l>>r;

		for (i = 0; i < n; ++i)
		{
			cin>>a[i];
			if(a[i]<l)
			{
				v.push_back(l-a[i]);
				out+=l-a[i];
			}
			else if(a[i]>r)
			{
				v.push_back(a[i]-r);
                out+=a[i]-r;
			}
		}

		sort(v.begin(),v.end());

		//vector<int>::iterator i = v.begin();
		/*for(i=0;i<v.size();i++)
		{
			cout<<v[i]<<" ";
		}
        cout<<endl<<"**"<<endl;
        */
		for(i=0;i<n;i++)
		{
			cout<<out<<" ";
            if(out>0)
            {
                out=out-v[v.size()-1-i];
            }
		}
		cout<<endl;
	}

	return 0;
}
