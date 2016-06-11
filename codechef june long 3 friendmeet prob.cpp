#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,c,v,c1,v1,flag,k,a[7][2];
	long double area,triangle,p;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d%d%d%d",&c,&v,&c1,&v1);

        if(c1==0 && v1 == 0)
            printf("0.000000\n");
        else
        {
            k= 0;
            a[0][0] = 0;
            a[0][1] = 0;

            if(c>=v)
            {
                k++;
                a[k][1] = 0;
                a[k][0] = v1;

                if(v1 > c)
                {
                    a[1][0] = 0;
                    k--;
                }

                k++;
                a[k][0] = c;
                a[k][1] = c-v1;

                if(c-v1 < 0)
                {
                    a[k][0] = 0;
                    a[k][1] = 0;
                    k--;
                }
                k++;

                if(v1 < c-v)
                {
                    a[k][1] = 0;
                    a[k][0] = 0;
                }
                else
                {
                    a[k][1] = v;
                    a[k][0] = c;
                    k++;
                }

                a[k][0] = v1+v;
                a[k][1] = v;

                if(v1 + v > c)
                {
                    a[k][0] = 0;
                    a[k][1] = 0;
                    k--;
                }
                k++;

                a[k][0] = v-c1;
                a[k][1] = v;

                if(v-c1 < 0)
                {
                    a[k][0] = 0;
                    a[k][1] = 0;
                    k--;
                }
                k++;

                a[k][0] = 0;
                a[k][1] = c1;

                 if(c1 > v)
                    a[k][1]=0,k--;

                k++;
            }
            else
            {
                k++;
                a[k][1] = 0;
                a[k][0] = v1;

                if(v1 > c)
                    a[k][0] = 0,k--;
                k++;
                a[k][0] = c;
                a[k][1] = c-v1;

                if(c-v1 < 0)
                {
                    a[2][0] = 0;
                    a[2][1] = 0;
                    k--;
                }
                k++;

                a[k][0] = c;
                a[k][1] = c1+c;

                if(c1+c > v)
                {
                    a[k][0] = 0;
                    a[k][1] = 0;
                    k--;
                }
                k++;

                if(c1 < v-c1)
                {
                    a[k][1] = 0;
                    a[k][0] = 0;
                }
                else
                {
                    a[k][1] = v;
                    a[k][0] = c;
                    k++;
                }


                a[k][0] = v-c1;
                a[k][1] = v;

                if(v-c1 < 0)
                {
                    a[k][0] = 0;
                    a[k][1] = 0;
                    k--;
                }
                k++;

                a[k][0] = 0;
                a[k][1] = c1;

                 if(c1 > v)
                    a[k][1]=0,k--;

                k++;
            }

            /*for(int i = 0;i<k;i++)
            {
                cout<<a[i][0]<<" "<<a[i][1]<<endl;
            }*/


            area = c*v;
            triangle = 0;

            for(int i =1 ;i< k-1 ;i++)
            {
                triangle += (a[i][0]*a[i+1][1] - a[i+1][0]*a[i][1]);
            }
            triangle = abs(triangle)/2;
            p = triangle/area;
            printf("%llf\n",p);
        }
	}
	return 0;
}
