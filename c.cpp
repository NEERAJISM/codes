#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb  push_back
#define mp make_pair
#define mod 1000000009

void fun(int a[][10])
{
    int i,j;

    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            a[i][j] = 5;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j,k,n,m,x,y,ttt,t,src;

    int a[10][10];

    fun(a);

    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            cout<<a[i][j]<<" ";
    return 0;
}

/*
4 4
1 2 3
2 3 6
3 4 5
4 1 8
*/
