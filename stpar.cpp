#include<iostream>
using namespace  std;
int main()
{
    int n,a[100000],chk,i,j,b[100000],top,flag;

    while(1)
    {
        cin>>n;
        top=-1;
        if(n==0)
            break;
        else
        {
            chk=1;
            flag=0;
            for(i=0;i<n;i++)
                cin>>a[i];

            i=0;
            while(chk!=n)
            {
                if(top>=0&&b[top]==chk)
                {
                    top--;
                    chk++;
                }
                else
                {
                    while(a[i]!=chk&&i<n)
                    {
                        cout<<a[i]<<" "<<chk<<endl;
                        top++;
                        b[top]=a[i];

                        cout<<b[top]<<endl;

                        if(b[top]>b[top-1]&&top>=1)
                        {
                            cout<<"end "<<b[top]<<endl;
                            flag=1;
                            break;
                        }

                        i++;
                    }

                    if(a[i]==chk)
                    {
                        chk++;
                        i++;
                    }
                }
                if(flag==1)
                    break;
            }

            if(flag==1)
                cout<<"no"<<endl;
            else
                cout<<"yes"<<endl;

        }
    }
    return 0;
}
