#include<iostream>
#include<climits>
using namespace std;
int n,p[100],m[100][100],s[100][100];

void printsolution(int i,int j)
{
    if(i==j)
        cout<<"A"<<i<<" ";
    else
    {
        cout<<"(";
        printsolution(i,s[i][j]);
        printsolution(s[i][j]+1, j);
        cout<<")";
    }
}

int matrixchain(int p[])
{
    int i,k,j,l,q;
//as here globally declared so already 0 hence  no need to make i,i as "0"

    for(l=2 ;l<=n; l++)
    {
        for(i=1; i<=n-l+1 ;i++)
        {
            j=i+l-1;
            m[i][j] = INT_MAX;

            for(k=i; k < j ;k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

int main()
{
    cout<<"enter the no. of matrices to be multiplied: ";
    cin>>n;

    for(int i=0;i<=n ; i++)
        cin>>p[i];

    cout<<"the min no. of multiplications required are: "<<matrixchain(p)<< endl<<endl;

    printsolution(1,n);
    return 0;
}
