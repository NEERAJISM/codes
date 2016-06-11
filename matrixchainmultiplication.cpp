/* matrix chain multiplication by neeraj patidar 29/3/15*/

#include<iostream>
using namespace std;
int n,p[100],m[100][100],s[100][100];
int main()

{

    cin>>"enter the no. of matrices to be multiplied"
    cin>>n;

    for(int i=0;i<=n;i++)
        cin>>p[i];

    matrixchainorder();

}
