#include <iostream>
#include <climits>
using namespace std;
int n=4,q ,temp1,g[5][5],i,j,path=0,flag,temp2,maintemp[5],temp3[5];

int tvsp(int temp[],int i)
{
    temp[i] =1;
	flag =0;

    for(int h2=1 ; h2<=n ; h2++)
        temp3[h2] = temp[h2];

	for(int k=2;k<=n;k++)
	{
        temp1 = INT_MAX;
        cout<<k<<endl;

        if(temp[k] != 1 && i!=k)
        {

            flag = 1;
            q = g[i][k] + tvsp(temp,k);

            if(temp1 > q)
            {
                temp2 = k;
                temp1 = q;
            }
        }
	}

	for(int h2=1 ; h2<=n ; h2++)
        temp[h2] = temp3[h2];

	if(flag !=1)
		temp1 = g[i][1];

    //for(int h2 =1 ;h2<=n ;h2++)
        //cout<<temp[h2]<<" ";

    //cout<<endl;

	path = path + temp1;
	//cout<<"path : "<<path<<endl;
	return path;
}

int main()
{
    int temp[5];

	for(i=1;i<=n;i++)
    {
        temp[i] =0;
		for(j=1;j<=n;j++)
			cin >> g[i][j];
    }
	cout<<"minimum weight is : "<<tvsp(temp,1);

	return 0;
}
//0 10 15 20 5 0 9 10 6 13 0 12 8 8 9 0
