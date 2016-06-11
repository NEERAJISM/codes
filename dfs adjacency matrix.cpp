
//depth first search
#include <bits/stdc++.h>
using namespace std;
int b[5];
int main()
{
    int a[5][5],src,i,j,temp;

    stack<int> s;

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            cin>>a[i][j];

    cout<<"enter the source vertex :";
    cin>>src;

    s.push(src);
    b[src] =1;

    while(s.empty() != 1)
    {
        temp = s.top();
        cout<<temp<<" ";
        s.pop();

        for(i=0;i<5;i++)
        {
            if(a[temp][i]!=0 && b[i]==0)
                s.push(i),b[i]=1;
        }
    }
    return 0;
}
