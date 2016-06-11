//matrix chain multiplication naive neeraj patidar 30/3/15

#include <iostream>
#include <climits>
using namespace std;
int temp,m[100][100],s[100][100],n,p[100];

int matrixchain(int i,int j)
{
    if(m[i][j] != 0 )
        return m[i][j];

    if(i==j)
        m[i][j] = 0;
    else
    {
        m[i][j] = INT_MAX;
        for(int k=i ;k<j ;k++)
        {
            temp = matrixchain(i,k) + matrixchain(k+1,j) + p[i-1]*p[k]*p[j];

            if(m[i][j] > temp)
                m[i][j] = temp;
        }
    }
    return m[i][j];
}

int main()
{
    cout<<"enter the no. of the matrices to be multiplied: ";
    cin>>n;

    for(int i=0;i<=n;i++)
        cin>>p[i];

    matrixchain(1,n);
    cout<<"the min. no. of multiplication to be done are : "<< matrixchain(1,n);
    return 0;
}
