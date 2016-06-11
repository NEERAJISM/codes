#include <iostream>
#include <cstdio>
using namespace std;
void constructseg(int a[],int b[],int low,int high,int pos)
{
    if(low==high)
    {
        b[pos] = a[low];
        return;
    }

    int mid= (low+high)/2;
    constructseg(a,b,low,mid,2*pos+1);
    constructseg(a,b,mid+1,high,2*pos+2);
    b[pos] =b[2*pos+1]+b[2*pos+2];
}


int rangesum(int b[],int x,int y,int low,int high,int pos,int sum)
{
    //total overlap
    if(x<=low && y>=high)
    {
        cout<<"/*/*";
        sum+=b[pos];
        return sum;
    }
    //nooverlap
    if(x>high || y<low)
        return sum;

    //partial overlap
    int mid = (low + high)/2;
    return (rangesum(b,x,y,low,mid,2*pos+1,sum)+rangesum(b,x,y,mid+1,high,2*pos+2,sum));

}

void update(int b[],int index,int value,int low,int high,int sindex)
{
    if(low==high)
    {
        b[sindex] = value;
        return;
    }

    int mid= (low+high)/2;

    if(index<=mid)
        update(b,index,value,low,mid,2*sindex+1);
    else
        update(b,index,value,mid+1,high,2*sindex+2);

    b[sindex] = b[2*sindex+1] + b[2*sindex+2];
}


int main()
{
    int a[100],i,j,n;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int b[2*n];

    constructseg(a,b,0,n-1,0);

    for(i=0;i<2*n-1;i++)
        printf("%d ",b[i]);

    printf("\n");

    int x,y;
    scanf("%d%d",&x,&y);

    cout<<rangesum(b,x,y,0,n-1,0,0);

    int index,value;
    scanf("%d%d",&index,&value);
    //update
    update(b,index,value,0,n-1,0);

    for(i=0;i<2*n-1;i++)
        printf("%d ",b[i]);

    printf("\n");



return 0;
}
