#include <iostream>
#include <cstdio>
using namespace std;

typedef struct{
    int d[501];
}set1;

int main()
{
    int n,q,a,b,i,index[10000],i1,i2,flag,length,temp[1000],k,j,nunion=0;
    string union1 = "UNION",get="GET",query;


    scanf("%d%d",&n,&q);

    set1 myset[n];

    for(i=1;i<=n;i++)
    {
        index[i]=i;
        myset[i].d[0]=1;
        myset[i].d[1]=i;
    }

    while(q--)
    {
        cin>>query;
        scanf("%d%d",&a,&b);

        flag=0;
        if(query == union1)
        {
            nunion++;
            for(i=1;i<=n;i++)
            {
                if(index[i] == a)
                {
                    flag++;
                    i1 = i;
                }
                else if(index[i]==b)
                {
                    flag++;
                    i2 = i;
                }

                if(flag==2)
                    break;
            }

            length = myset[i1].d[0] + myset[i2].d[0];


            k=1;
            i=1;
            j=1;
            while(i<=myset[i1].d[0] &&j<= myset[i2].d[0])
            {
                if(myset[i1].d[i] <myset[i2].d[j])
                {
                    temp[k]= myset[i1].d[i];
                    i++;
                }
                else
                {
                    temp[k]= myset[i2].d[j];
                    j++;
                }
                k++;
            }

            while(i<=myset[i1].d[0] )
            {
                temp[k]= myset[i1].d[i];
                i++;
                k++;
            }

            while(j<= myset[i2].d[0])
            {
                temp[k]= myset[i2].d[j];
                j++;
                k++;
            }

            myset[i1].d[0] = length;

            for(i=1;i<=length;i++)
                myset[i1].d[i] = temp[i];

            index[i1] = n+nunion;

            //cout<<index[i1]<<endl;

            //for(i=1;i<=length ;i++)
                //cout<<myset[i1].d[i]<<" ";
        }
        else
        {
            for(i=1;i<=n;i++)
                if(index[i]==a)
                    break;

            printf("%d\n",myset[i].d[b]);
        }
    }
return 0;
}
