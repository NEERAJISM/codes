#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,q,a[100005],x,y,k,dummy[100005],i,j,i1;
    string c;
    scanf("%d%d",&n,&q);

    cin>>c;
    for(i=0;i<n;i++)
        a[i] = (int)c[i];

    for(i=0;i<q;i++)
    {
        scanf("%d%d%d",&x,&y,&k);

        if(k==1)
            sort(a+x-1,a+y);
        else
        {
            j=0;
            for(i1=x-1;i1<y;i1++,j++)
                dummy[j] = a[i1];

            sort(dummy,dummy+j);

            for(i1=j-1;i1>=0;i1--,x++)
                a[x-1] = dummy[i1];
        }
    }

    for(i=0;i<n;i++)
        printf("%c",(char)a[i]);
return 0;
}
