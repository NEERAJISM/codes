#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j,sum,p,x;

    cout<<"enter no of process and no of resources\n";
    cin>>n>>m;

    int max_res[m+1];
    int avail_res[m+1];
    int curr_alloc[n+1][m+1];
    int max_req[n+1][m+1];
    //bool mark_proc[m+1];

    cout<<"enter the max instances of each resources\n";
    for(i=0;i<m;i++)
    cin>>max_res[i];

    cout<<"enter the currently allocated no of resource instances to each process\n";
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    cin>>curr_alloc[i][j];

    cout<<"enter the maximum required no of resource instances to each process\n";
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    cin>>max_req[i][j];
    
    //calculating the available no of instances of each resources;
    for(i=0;i<m;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        {
            sum+=curr_alloc[j][i];
        }

        avail_res[i]=max_res[i]-sum;
    }

    queue<int> q;
    for(i=0;i<n;i++)
    q.push(i);
    
    
    //running the Banker's Algorithm
    while(!q.empty())
    {
        int flag=1;

        p=q.front();   
        q.pop();

        for(j=0;j<m;j++)
        {
            x=max_req[p][j]-curr_alloc[p][j];
            if(x>avail_res[j])
            {
                q.push(p);
                flag=0;
                break;
            }
        }
        
        if(flag)
        {
            for(j=0;j<m;j++)
            avail_res[j]+=curr_alloc[p][j];

            cout<<"process no--"<<p+1<<endl;
        }
    }

    return 0;
}
