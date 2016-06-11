#include<iostream>
using namespace std;
float x1,x2,x3,x4;
int nwtn(float x1,int s)
{

    x2=x1*x1+x1-s+1;
    x3=2*x1+1;
    x4=x1-x2/x3;
    if((int)x1==(int)x4)
        return((int)x1);
    else
        nwtn(x4,s);

}
int main()
{
    long long int n,t,s,t1,t2;
    cin>>t;
    while(t-->0)
    {
        cin>>n>>s;
        t1=(n*(n+1))/2;
        if(s==t1)
            cout<<"0"<<endl;
        else
        {
            s=t1-s;
            t2=nwtn((float)s/2,s);
            cout<<t2+1<<endl;
        }
    }
    return 0;
}
