#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,c,v,t1,t2,flag,k1,k2,a1[4][2],a2[4][2];
	long double area,triangle1,triangle2,p;
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%lld%lld",&c,&v,&t1,&t2);

        if(t1==0 && t2 == 0)
            printf("0.000000\n");
        else
        {
            triangle1 = 0;
            triangle2 = 0;

            if(t2<c)
            {
                a1[0][0] = t2;
                a1[0][1] = 0;

                a1[1][0] = c;
                a1[1][1] = 0;

                k1 = 2;
                if(v+t2<c)
                {
                    a1[k1][0] = c;
                    a1[k1][1] = v;

                    k1++;

                    a1[k1][0] = v+t2;
                    a1[k1][1] = v;
                }
                else
                {
                    a1[k1][0] = c;
                    a1[k1][1] = c-t2;
                }

                for(int i =0 ;i<=k1 ;i++)
                    triangle1 += (a1[i][0]*a1[(i+1)%(k1+1)][1] - a1[(i+1)%(k1+1)][0]*a1[i][1]);

                triangle1 = abs(triangle1)/2;
        }

        if(t1<v)
        {
            a2[0][0] = 0;
            a2[0][1] = t1;

            a2[1][0] = 0;
            a2[1][1] = v;

            k2 = 2;
            if(c+t1<v)
            {
                a2[k2][0] = c;
                a2[k2][1] = v;

                k2++;

                a2[k2][0] = c;
                a2[k2][1] = c+t1;
            }
            else
            {
                a2[k2][0] = v-t1;
                a2[k2][1] = v;
            }
            for(int i =0 ;i<=k2 ;i++)
            {
                triangle2 += (a2[i][0]*a2[(i+1)%(k2+1)][1] - a2[(i+1)%(k2+1)][0]*a2[i][1]);
            }
            triangle2 = abs(triangle2)/2;
        }

        area = c*v;
        triangle1 = area - triangle1- triangle2;
        p = triangle1/area;
        printf("%llf\n",p);
        }
	}
	return 0;
}
