#include <iostream>
using namespace std;
int main()
{
    int n,count1,count2,a[100000][2],i ,previous,next;
    cin>>n;

    if(n>2)
    {
        count1 =2;
        count2 = 2;
    }
    else
    {
        count1 = n;
        count2 =n;
    }

    for(i=0;i<n;i++)
        cin>>a[i][0]>>a[i][1];

    previous = a[0][0];

    for(i=1;i<n-1;i++)
    {
        if(a[i][0]-a[i][1] > previous)
        {
            count1++;
            previous=a[i][0];
        }
        else
        {
            if(a[i][0]+a[i][1] < a[i+1][0] )
            {
                count1++;
                previous = a[i][0]+a[i][1];
            }
            else
                previous = a[i][0];
        }
    }

    next = a[n][0];
    for(i=n-1;i>=1;i--)
    {
        if(a[i][0]+a[i][1] < next)
        {
            count2++;
            next=a[i][0];
        }
        else
        {
            if(a[i][0]-a[i][1] > a[i-1][0] )
            {
                count2++;
                next = a[i][0]-a[i][1];
            }
            else
                next = a[i][0];
        }
    }

    if(count2 > count1)
        count1 = count2;
    cout<<count1;
    return 0;
}
