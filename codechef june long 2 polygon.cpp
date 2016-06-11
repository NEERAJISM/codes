#include <iostream>
using namespace std;
#define INF 1000000003

typedef struct point
{
    int x;
    int y;
};

typedef struct polygon
{
    point mypoint[100000];
};

polygon mypoly[100000-];

int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(point p1, point q1, point p2, point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    return false;
}

// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(int i1, int m, point p)
{
    point extreme = {INF, p.y};

    int count = 0, i = 0;

    for(int k=0; k<m ; k++)
        if (doIntersect(mypoly[i1].mypoint[k], mypoly[i1].mypoint[(k+1)%m], p, extreme))
            count++;

    return count&1;
}

int main()
{
    int t,n,m[100000],counti[100000];
    cin>>t;

    while(t--)
    {
        cin>>n;

        for(int i =0 ; i< n ; i++)
        {
            counti[i] = 0;
            cin>>m[i];

            for(int j=0 ; j<m[i] ; j++)
                cin>>mypoly[i].mypoint[j].x>>mypoly[i].mypoint[j].y;
        }

        for(int i = 0 ;i<n;i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(j != i)
                {
                    point p;
                    p = mypoly[j].mypoint[0];

                    if(isInside(i, m[i], p))
                        counti[i]++;
                }
            }
        }

        for(int i = 0; i<n ;i++)
            cout<<counti[i]<<" ";

        cout<<endl;
    }
    return 0;
}
