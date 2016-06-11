#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,a[51],b[51],sum,flag,mag,k,c[51],l,l1,j,size1,i;

	cin>>t;
	while(t--)
	{
	    l=1;
		sum = 0;
		flag = 0;

		cin>>n;

		for (i = 1; i <= n; ++i)
		{
			cin>>a[i];

			if(a[i]>0)
            {
                c[l] =i;
                l++;
            }

			if(a[i] >= n)
				flag = 1;

			b[i]=0;
			sum+=a[i];
		}
/*
		for (i = 1; i <= l; ++i)
		{
			cout<<c[i]<<" ";
		}
		cout<<endl;
*/

		if(flag==1 || sum != n)
			cout<<"-1"<<endl;
		else
		{
		    l = l-1;
		    size1 = l;

			for (i = 1; i <= n; ++i)
			{
                mag = a[i];

                cout<<"size1 "<<size1<<endl;

                if(size1 > 0)
                {
                    for(l1=l;l1>0;l1--)
                    {
                        if (mag == 0)
                            break;

                        if(c[l1]!=i && b[c[l1]] == 0)
                        {
                            mag--;
                            b[c[l1]] = i;
                            size1--;
                        }
                    }
                }

                if(mag !=0)
                {
                    for(int j = n; j>0 ;j--)
                    {
                        cout<<"***\n";
                        if(mag==0)
                            break;
                        if( j!=i && b[j]==0)
                        {
                            b[j]==i;
                            mag--;
                        }
                    }
                }
			}

			for (i = 1; i <= n; ++i)
				cout<<b[i]<<" ";
			cout<<endl;
		}
	}
return 0;
}
