#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100005],b[1000005],max1=-1,n1,c[100005],mag,result[100005][3],min1,min2,min3,i;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(max1 < a[i])
            max1= a[i];

        b[a[i]]++;

        if(b[a[i]]>mag)
            mag=b[a[i]];
    }
    n1=0;
    for(i=1;i<=max1;i++)
    {
        if(b[i]==mag)
        {
            c[n1]=i;
            n1++;
        }
    }

    int assign1,temp=100000000,temp1;
    for(i=0;i<n1;i++)
    {
        int j = 1;
        while(a[j]!=c[i])
            j++;

        result[i][0] = j;

        for(j;j<=n;j++)
        {
            if(a[j]==c[i])
            {
                result[i][1] = j;
            }
        }
        temp1= result[i][1] - result[i][0]+1;

        if(temp1<temp)
        {
            temp = temp1;
            assign1 = i;
        }

    }
    printf("%d %d\n",result[assign1][0],result[assign1][1]);
return 0;
}
