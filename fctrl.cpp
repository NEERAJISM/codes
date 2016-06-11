
#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;
int main()
{
    int t,n,i,c,n1;
    clock_t t1,t2;
    cin>>t;
    while(t--)
    {
        t1=clock();
        cin>>n;
        c=0;
        i=1;
        while(1)
        {
            n1=n/pow(5,i);
            c=c+n1;
            i++;
            if(n1==0)
                break;
        }
        cout<<c<<endl;
        t2=clock();
    float diff =((float)t2-(float)t1);
    float seconds=diff/CLOCKS_PER_SEC;
    cout<<"time = "<<seconds<<endl;
    }
    return 0;
}
