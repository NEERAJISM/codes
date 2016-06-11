#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
char c[52][52];
int alpha[52][52];
int maxlength,h,w;

void matrixbfs(queue< pair<int,int> > q , int length)
{
    /*cout<<"**"<<endl;

     for(int i=0;i<h;i++)
     {
        for(int j=0;j<w;j++)
            cout<<alpha[i][j];
        cout<<endl;
     }*/

    maxlength = length > maxlength ? length:maxlength;
    queue< pair<int,int> > q2;

    while(q.empty() == 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x-1>=0 && alpha[x-1][y] == 0 && c[x-1][y] ==char( 65 + length))
        {
            alpha[x-1][y] = 1;
            q2.push(make_pair(x-1,y));
        }

        if(x+1<h && alpha[x+1][y] == 0 && c[x+1][y] ==char( 65 + length))
        {
            alpha[x+1][y] =1;
            q2.push(make_pair(x+1,y));
        }

        if(y-1>=0 && alpha[x][y-1] == 0 && c[x][y-1] ==char( 65 + length))
        {
            alpha[x][y-1] =1;
            q2.push(make_pair(x,y-1));
        }

        if(y+1<w && alpha[x][y+1] == 0&& c[x][y+1] ==char( 65 + length))
        {
            alpha[x][y+1] =1;
            q2.push(make_pair(x,y+1));
        }

        if(x-1>=0&&alpha[x-1][y-1] == 0 && y-1>=0 && c[x-1][y-1] ==char( 65 + length))
        {
            alpha[x-1][y-1] =1;
            q2.push(make_pair(x-1,y-1));
        }

        if(x-1>=0 && y+1<w &&alpha[x-1][y+1] ==0 && c[x-1][y+1] ==char( 65 + length))
        {
            alpha[x-1][y+1] =1;
             q2.push(make_pair(x-1,y+1));
        }
        if(x+1<h&& y-1>=0 &&alpha[x+1][y-1] == 0 && c[x+1][y-1] ==char( 65 + length))
        {
            alpha[x+1][y-1] =1;
            q2.push(make_pair(x+1,y-1));
        }
        if(x+1<h && y+1 <w &&alpha[x+1][y+1] == 0 && c[x+1][y+1] ==char( 65 + length))
        {
            alpha[x+1][y+1] =1;
            q2.push(make_pair(x+1,y+1));
        }
    }

    length++;

    if(q2.empty()==0)
    {
        matrixbfs(q2,length);
    }
}

int main()
{
    int i,j,c1=1;
    while(1)
    {
        scanf("%d%d",&h,&w);

        if(h==0 && w==0)
            break;
        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
                cin>>c[i][j];

        maxlength= 0;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(c[i][j] == 'A')
                {
                    for(int i2=0;i2<h;i2++)
                        for(int j2=0;j2<w;j2++)
                            alpha[i2][j2] = 0;

                    int length = 1;
                    queue< pair<int,int> > q;
                    q.push(make_pair(i,j));
                    alpha[i][j] =1;
                    matrixbfs(q,length);
                }
            }
        }
        printf("Case %d: %d\n",c1,maxlength);
        c1++;
    }
return 0;
}
