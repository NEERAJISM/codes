#include<bits/stdc++.h>
using namespace std;
int c[4][4];

void multiply(int*a,int*b,int r11,int r12,int c11,int c12,int r21,int r22,int c21,int c22 )
{
    if(r11==r12&&c11==c12&&r21==r22&&c21==c22)
    {
        c[r11][c11]=a[r11][c11]*b[r21][c21];
        return ;
    }
    else
    {

    }
}


int main()
{
    int i,j,a[4][4],b[4][4],c[4][4];

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            cin>>a[i][j];

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            cin>>b[i][j];

            multiply(a,b,0,3,0,3,0,3,0,3);

return 0;
}
