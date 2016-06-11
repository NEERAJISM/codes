#include <bits/stdc++.h>
using namespace std;
long long int t,n,r[100000],f[100000],i,j,temp[100000],flag[100000],sum,count1,k,q1;
int main()
{
	cin>>t;
	while(t--)
	{
		sum = 0;
		cin>>n;

		for(i=1 ; i<=n ; i++)
		{
		    cin>>f[i];
            flag[i] =0;
		}
        //cout<<"/*/*/\n";

		for(i=1 ; i<=n ; i++)
			cin>>r[i];


		for(i=1 ; i<=n ; i++)
		{
			if(flag[i]==0 && r[i]>=0)
			{
				count1 = r[i];
				flag[i] = 1;
				j=i;
				k=0;

				while(flag[f[j]] != 1)
				{
					temp[k] = f[j];
					count1 += r[f[j]];
					flag[f[j]] = 1;
					j = f[j];
					k++;
				}

				if(count1>0)
				{
					sum += count1;
				}
				else
				{
					for(q1 = 0; q1 < k ;q1++)
						flag[temp[q1]] =0;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
