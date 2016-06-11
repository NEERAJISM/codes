#include<iostream>
using namespace std;
char a[200006],b[200006];
int c[200005];
// add 1 to the final index

int main()
{
    int n,i,count1=0,j,k=0,m1=0,n1=0,flag=0;
    char g;
    cin>>n;

    for(i=0;i<n;i++)
        cin >> a[i];e

    for(i=0;i<n;i++)
    {
        cin >> b[i];

        if(b[i]!=a[i])
        {
            count1++;
            c[k] = i;
            k++ ;
        }
    }

    cout<<"k "<<count1<<endl;

    if(count1 ==1)
    {
        cout<<"1"<<endl;
        cout<<"-1"<<" "<<"-1";
    }
    else
    {
        for(i=0;i<k;i++)
        {
            g=a[c[i]];

            //cout<<g<<endl;

            for(j=0;j<k;j++)
            {

                //cout<<"/*/*/*0\n";
                if(b[c[j]]==g)
                {
                    //cout<<"/*count/*/*"<<count<<endl;
                    flag=1;
                    count--;
                    m1=c[i]+1;
                    n1=c[j]+1;

                    if(a[c[j]]==b[c[i]])
                    {

                        flag=2;
                        //cout<<"***flag "<<flag<<endl;
                        count--;
                        break;
                    }
                }
            }
            //cout<<"***flag "<<flag<<endl;
            if(flag==2)
                break;
        }

        cout<<count<<endl;
        if(flag==1||flag==2)
            cout<<n1<<" "<<m1;
        else
            cout<<"-1"<<" "<<"-1";
    }

return 0;
}
