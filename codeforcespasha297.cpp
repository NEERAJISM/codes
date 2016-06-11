#include<iostream>
#include<string.h>
using namespace std;
string ipstring;
int main()
{
    int j,i,m,n,check[100000],k;
    char temp;
    cin>>ipstring;
    n= ipstring.size();

    cin>>m;

    for(i=0;i<m;i++)
        cin>>check[i];

    for(i=0;i<m;i++)
    {
        j=check[i];

        for(k=j;k<=(j+(n-j+1-j+1)/2-1);k++)
        {
            temp=ipstring[k-1];
            ipstring[k-1]=ipstring[n-k];
            ipstring[n-k]=temp;
        }
    }

    cout<<ipstring;

    return 0;
}
