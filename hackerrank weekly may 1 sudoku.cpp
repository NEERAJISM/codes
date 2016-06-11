#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,a[10][10],i,j,k=1,sum,b[10],flag,x1,x2,y1,y2,dup1,dup2,req,i1;

	cin>>t;

	while(k <= t)
	{
		for(i=1 ; i<=9 ; i++)
		{
			sum =0;
			for(j=1 ; j<=9 ; j++)
			{
				cin>>a[i][j];
				sum+=a[i][j];
			}
			a[i][0] = sum;
		}

		for(i=1 ; i<=9 ; i++)
		{
			sum =0;
			for(j=1 ; j<=9 ; j++)
			{
				sum+=a[j][i];
			}
			a[0][i] = sum;
		}

		cout<<"Case #"<<k<<":"<<endl;
		flag = 0;
		while(1)
		{
			x1=0;
			y1=0;
			for(i=1 ; i<= 9 ;i++)			//column check
			{
				if(a[0][i] != 45)
				{
					flag = 1;
					y1=i;

					vector<int> v(10,0);

					for(j=1 ; j<=9 ; j++)
					{
                        if(a[j][0] != 45)
                        {
                            x1 = j;
                            break;
                        }
					}

					if(x1!=0 && y1 !=0)
						break;
				}
			}

			if(i==10)
				break;

			req = a[x1][y1] + 45 - a[0][y1];

			x2 = 0;
			y2 = 0;
			for(i;i<=9;i++)
			{
				if(a[0][i] != 45)
				{
					y2 = i;
					vector<int> v(10,0);

					for(j=1 ; j<=9 ; j++)
					{
                        if(a[j][0] != 45 && a[j][y2] == req)
                        {
                            x2 = j;
                            break;
                        }
					}

					if(x2!=0 && y2 !=0)
						break;
				}
			}

			a[0][y1] = 45;
			a[0][y2] = 45;
			a[x1][0] = 45;
			a[x2][0] = 45;

			if(x1<x2 ||(x1==x2)&&(y1<y1))
                cout<<"("<<x1<<","<<y1<<") <-> ("<<x2<<","<<y2<<")"<<endl;
            else
                cout<<"("<<x2<<","<<y2<<") <-> ("<<x1<<","<<y1<<")"<<endl;

		}

		if(flag == 0)
			cout<<"Serendipity"<<endl;
		k++;
	}
}
