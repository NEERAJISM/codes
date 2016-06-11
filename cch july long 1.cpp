#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int t,i,color[6][7];
    string s;
    scanf("%d",&t);

    while(t--)
    {
        for(i=0;i<6;i++)
            color[i][0] = 0;

        for(i=0;i<6;i++)
        {
            cin>>s;

            if(s=="black")
            {   //cout<<"0"<<"**"<<endl;
                color[0][0]++;
                color[0][color[0][0]] = i;
            }
            else if(s=="blue")
            {
               // cout<<"1"<<"**"<<endl;
                color[1][0]++;
                color[1][color[1][0]] = i;
            }
            else if(s=="red")
            {
                //cout<<"2"<<"**"<<endl;
                color[2][0]++;
                color[2][color[2][0]] = i;
            }
            else if(s=="green")
            {
                //cout<<"3"<<"**"<<endl;
                color[3][0]++;
                color[3][color[3][0]] = i;
            }
            else if(s=="yellow")
            {
                //cout<<"4"<<"**"<<endl;
               color[4][0]++;
                color[4][color[4][0]] = i;
            }
            else
            {
                //cout<<"5"<<"**"<<endl;
                color[5][0]++;
                color[5][color[5][0]] = i;
            }
        }

        /*for(i=0;i<6;i++)
            cout<<color[i][0]<<" / "<<endl;


        for(i=0;i<6;i++)
        {
            for(int j = 1;j<=color[i][0];j++)
                cout<<color[i][j]<<" - ";
            cout<<endl;
        }*/

        int flag = 0,best1=-1;
        for(i=0;i<6;i++)
        {
            if(color[i][0]==3)
            {
                flag=1;
                best1=i;
                break;
            }
            else if(color[i][0]==4)
            {
                flag =4;
                best1 =i;
                break;
            }
            else if(color[i][0]>=5)
            {
                flag=2;
                break;
            }
        }

        if(flag==0)
            printf("NO\n");
        else if(flag == 1)
        {
            flag = 0;
            if(color[best1][1]==0&&color[best1][2]==2&&color[best1][3]==4)
            {
                flag = 1;
            }
            else if(color[best1][1]==0&&color[best1][2]==3&&color[best1][3]==4)
            {
                flag = 1;
            }
            else if(color[best1][1]==1&&color[best1][2]==3&&color[best1][3]==4)
            {
                flag = 1;
            }
            else if(color[best1][1]==1&&color[best1][2]==2&&color[best1][3]==4)
            {
                flag = 1;
            }
            else if(color[best1][1]==0&&color[best1][2]==2&&color[best1][3]==5)
            {
                flag = 1;
            }
            else if(color[best1][1]==0&&color[best1][2]==3&&color[best1][3]==5)
            {
                flag = 1;
            }
            else if(color[best1][1]==1&&color[best1][2]==3&&color[best1][3]==5)
            {
                flag = 1;
            }
            else if(color[best1][1]==1&&color[best1][2]==2&&color[best1][3]==5)
            {
                flag = 1;
            }

            if(flag == 0)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else if(flag == 4)
        {
            flag= 0;
            if(color[best1][1]==0&&color[best1][2]==1&&color[best1][3]==2 && color[best1][4]==3)
            {
                flag = 1;
            }
            else if(color[best1][1]==0&&color[best1][2]==1&&color[best1][3]==4 && color[best1][4]==5)
            {
                flag = 1;
            }
            else if(color[best1][1]==2&&color[best1][2]==3&&color[best1][3]==4&& color[best1][4]==5)
            {
                flag = 1;
            }

            if(flag == 1)
                printf("NO\n");
            else
                printf("YES\n");

        }
        else if(flag == 2)
            printf("YES\n");
    }
return 0;
}
