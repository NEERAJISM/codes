#include<iostream>
using namespace std;
int a[1000000][2],n;
int find1(int s,int c)
{
    if(s>n-1)
        return 0;
    else if(s==n-1)
        return c+a[s][0];
    else
    {
        int max1,max2,max3;

        max1=find1(s+a[s][1],c+a[s][0]);
        max2=find1(s+a[s][1]+1,c+a[s][0]);
        max3=find1(s+a[s][1]+2,c+a[s][0]);

        max2=max2>max1?max2:max1;
        max3=max3>max2?max3:max2;

        return max3;
    }
}

int main()
{
    int t,i,j,max1,max2,max3;

    cin>>t;

    while(t-->0)
    {
        cin>>n;

        for(i=0;i<n;i++)
            cin>>a[i][0];
        for(i=0;i<n;i++)
            cin>>a[i][1];

        max1=find1(0+a[0][1],a[0][0]);
        max2=find1(0+a[0][1]+1,a[0][0]);
        max3=find1(0+a[0][1]+2,a[0][0]);

        max2=max2>max1?max2:max1;
        max3=max3>max2?max3:max2;

        if(max3==0)
            cout<<"-1"<<endl;
        else
            cout<<max3<<endl;
    }
    return 0;
}
