#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k1,k2,temp,fights = 0,i,j,a,b;

    queue<int> q1;
    queue<int> q2;

    cin>>n;

    cin>>k1;
    for( i=0; i<k1; i++)
    {
        cin>>temp;
        q1.push(temp);
    }
   // cout<<"****";
    cin>>k2;

    for(i=0;i<k2;i++)
    {
        cin>>temp;
        q2.push(temp);
    }


    while(1)
    {
        if(q1.empty()==1 || q2.empty()==1 || fights > n*n)
            break;
        else
        {
            a=q1.front();
            b=q2.front();
            q1.pop();
            q2.pop();

            //cout<<q1.front()<<"*"<<endl;
            //cout<<q2.front()<<"*"<<endl;

            fights++;

            if(a>b)
            {
                q1.push(b);
                q1.push(a);
            }
            else
            {
                q2.push(a);
                q2.push(b);
            }
        }
    }

    if(fights > n*n)
        cout<<-1;
    else
    {
        if(q1.empty() != 1)
            temp = 1;
        else
            temp = 2;

        cout<<fights<<" "<<temp;
    }

    return 0;
}
