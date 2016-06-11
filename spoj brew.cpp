#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int h,i,j,w,a[100005],neg[100005],n2,val,pos,col,n;

    while(1)
    {
        scanf("%lld",&n);
        w=0;
        n2=0;
        if(n!=0)
        {
            for(i=0;i<n;i++)
            {
                scanf("%lld",&a[i]);
                if(a[i]<0)
                {
                    neg[n2] = i;
                    n2++;
                }
            }

            j=0;
            for(i=0;i<n2;i++)
            {
                val = -a[neg[i]];
                pos = neg[i];

                while(val!=0)
                {
                    if(a[j]>0)
                    {
                        if(a[j]>val)
                        {
                            w+= abs(pos-j)*val;
                            a[j] = a[j] - val;
                            val=0;
                            break;
                        }
                        else
                        {
                            w+= abs(pos-j)*a[j];
                            val-=a[j];
                            a[j] = 0;
                        }
                    }
                    j++;
                }
            }
            printf("%lld\n",w);
        }
        else
            return 0;
    }
return 0;
}
