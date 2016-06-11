//bfs
#include <bits/stdc++.h>
using namespace std;
int b[5];
int main()
{
    int a[5][5],src,i,j;

    queue<int> q;

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            cin>>a[i][j];

    cout<<"enter the source vertex ";
    cin>>src;

    q.push(src);


    cout<<"the breadth first traversal is :";

    while(q.empty() != 1)
    {
        cout<<q.front()<<" ";
        b[q.front()] = 1;

        for(i=0;i<5;i++)
            if(a[q.front()][i]!=0 && b[i]==0)
            {
                q.push(i);
                b[i] = 1;
            }
        q.pop();
    }

    return 0;
}
