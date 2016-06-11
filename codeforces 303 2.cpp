#include <iostream>
using namespace std;
int d[100000];
int main()
{
    string a,b;
    int i,distance =0,k=0;

    cin>>a;
    cin>>b;

    for(i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        {
            distance++;
            d[k] =i;
            k++;
        }
    }

    if(distance%2 > 0)
        cout<<"impossible";
    else
    {
        i=0;
        distance = distance/2;
        while(distance--)
        {
            if(b[d[i]]== '0')
                b[d[i]] = '1';
            else
                b[d[i]] = '0';
            i++;
        }

        cout<<b;
    }

return 0;
}
