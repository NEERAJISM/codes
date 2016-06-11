#include <iostream>
using namespace std;
int k[100][100];

int knapsack(int m ,int w[],int p[],int n)
{
	int i,j;

   //cout<<n<<m;
	for(i=0;i<=n;i++)
	{
		for(j=0 ;j<=m; j++)
		{
			if(i==0 || j==0)
				k[i][j] = 0;
			else if(w[i-1] <= m)
			{
				if(j- w[i-1] >=0 && k[i-1][j- w[i-1]]+ p[i-1]  > k[i-1][j]  )
                    k[i][j] = k[i-1][ j - w[i-1] ] + p[i-1];
				else
                    k[i][j] = k[i-1][j];
			}
			else
                k[i][j] = k[i-1][j];

		}
	}

	for(int i=0;i<=n;i++)
    {
        for(int j =0;j<=m;j++)
            cout<<k[i][j]<<" ";

        cout<<endl;
    }

    cout<<endl;

	return k[n][m];
}

int main()
{
	int w[100],p[100],n,m;

	cout<<"enter the no. of elements : ";
	cin>>n;
	cout<<"enter the weight of elements and their profits x \n";

	for(int i=0;i<n;i++)
		cin>>w[i]>>p[i];

	cout<<"enter the maximum capacity of knapsack \n";
	cin>>m;
	cout<<"the maximum profit which can be made is : "<<knapsack(m,w,p,n);

	return 0;
}
