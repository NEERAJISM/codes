//naive approach
#include <iostream>
using namespace std;

int knapsack(int w[],int p[],int n, int m)
{
    if(n==0 || m==0)
        return 0;

	if(m<w[n-1])
		return knapsack(w,p,n-1,m);
	else
	{
        if(p[n-1]+knapsack(w,p,n-1,m-w[n-1]) > knapsack(w,p,n-1,m))
            return p[n-1]+knapsack(w,p,n-1,m-w[n-1]);
        else
            return knapsack(w,p,n-1,m);
	}
}

int main()
{
	int w[100],p[100],n,m;

	cout<<"enter the no. of elements : ";
	cin>>n;
	cout<<"enter the weight of elements and their profits \n";

	for(int i=0;i<n;i++)
		cin>>w[i]>>p[i];

	cout<<"enter the maximum capacity of knapsack \n";
	cin>>m;
	cout<<"the maximum profit which can be made is : "<<knapsack(w,p,n,m);

	return 0;
}
