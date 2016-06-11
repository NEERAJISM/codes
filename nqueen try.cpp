#include <iostream>
#include <cstdio>
#include<vector>
#include <cmath>
#include <chrono>
int x[30],flag;
using namespace std::chrono;
using namespace std;
bool place(int k,int i)
{
	for(int j=1;j<k;j++)
	{
		if(x[j]==i || abs(x[j]-i)==abs(j-k))
			return false;
	}
	//cout<<k<<" "<<i<<endl;
	return true;
}

void nqueen(int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k] = i;
			if(k==n)
            {
                // for(int j=1;j<=n;j++)
                  //  cout<<x[j]<<" ";

                flag = 1;
                return;
            }
            else
                nqueen(k+1,n);

            if(flag == 1)
                return ;
		}
	}
}

int main()
{
	int n;
	cin>>n;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
	nqueen(1,n);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    cout<<endl<<"duration " << duration;
return 0;
}
