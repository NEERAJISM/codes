#include<stdio.h>
int a[11];
merge(b1,e1,b2,e2)
{
    int temp1[e1-b1+1],temp2[e2-b2+1],i1=0,j1=0,k1=0,temp3[e1-b1+e2-b2],l1=e1-b1+1,l2=e2-b2+1,j2;

    for(j2=0;j2<l1;j2++)
    {
        temp1[j2]=a[b1];
        b1++;
    }
     for(j2=0;j2<l2;j2++)
    {
        temp2[j2]=a[b2];
        b2++;
    }

    while(i1<l1&&j1<l2)
    {
        if(temp1[i1]<temp2[j1])
        {    temp3[k1]=temp1[i1];
             i1++;
        }
        else
        {   temp3[k1]=temp2[j1];
            j1++;
        }
        k1++;
    }

    if(i1<l1)
        {
            temp3[k1]=temp1[i1];
            i1++;
        }
    else
        {   temp3[k1]=temp2[j1];
            j1++;
        }

        for(j1=0;j1<10;j1++)
        {
            printf("%d\n",temp3[j1]);
        }
}

mergesort(int beg,int end)
{
   int n=end-beg;
    if(n>1)
    {
        int mid=(beg+end)/2;
        mergesort(beg,mid);
        mergesort(mid+1,end);

        merge(beg,mid,mid+1,end);

    }
}

int main()
{
    int i;

    printf("enter the elments of the array");

    for(i=0;i<11;i++)
        scanf("%d",&a[i]);

    mergesort(0,10);

return 0;
}
