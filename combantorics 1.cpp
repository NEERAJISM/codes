#include <iostream>
using namespace std;
int main()
{
    long long int r,c,op;

    cin>>r>>c;

    if(r%2>0)
        op= ((r-1)/2)*10+2*(c-1);
    else
        op = ((r-2)/2)*10+(2*(c-1)+1);

    cout<<op;
    return 0;
}
