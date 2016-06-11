#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


const int N = 100005;

struct S
{
    int l,r;
}tree[4000000];

int T;
int n,k;
int a[N];
int num[50];
int ans;
int v;
int str[50];
void input()
{
    int i;
    v = 1;
    scanf("%d%d", &n,&k);
    for (i = 1; i <= n; i ++)
    scanf("%d", a + i);
}

void init()
{
    tree[1].l = -1;
    tree[1].r = -1;
    v = 1;
    int i;
    num[0] = 1;
    for (i = 1; i <= 30; i ++)
    num[i] = num[i - 1] * 2;

}

void change (int x)
{
    int i;
    for (i = 0; i <= 30; i ++)
    str[i] = (num[i] & x);
}

void insert()
{
    int root = 1;
    int i ;
    for (i = 30; i >= 0; i --)
    {
       // printf("%d", str[i]);
        if ( str[i] == 0 )
        {
            if ( tree[root].l != -1 )
            {
                root = tree[root].l;
            }
            else
            {
                v ++;
                tree[root].l = v;
               // tree[v].l = -1;
               // tree[v].r = -1;
                root = v;
            }
        }
        else
        {
            if ( tree[root].r != -1)
            {
                root = tree[root].r;
            }
            else
            {
                v ++;
                tree[root].r = v;
               // tree[v].l = -1;
               // tree[v].r = -1;
                root = v;
            }
        }

    }
   // printf("\n");
}

int query()
{
    int root = 1;
    int ret = 0;
    int i;
    for ( i = 30; i  >= 0; i --)
    {
        if ( str[i] == 0)
        {
            if ( tree[root].r != -1)
            {
                ret += num[i];
                root = tree[root].r;
            }
            else
            {
                root = tree[root].l;
            }
        }
        else
        {
            if ( tree[root].l != -1)
            {
                root = tree[root].l;
            }
            else
            {
                ret += num[i];
                root = tree[root].r;
            }

        }
    }
    return ret;

}

void solve()
{
    int i;
    int now = a[1];
    int temp;
    ans = a[1];
    change(a[1]);
    insert();


    for (i = 2; i <= n; i ++)
    {
        //if ( a[i] > ans ) ans = a[i];
        //printf("%d %d\n", now, a[i]);
        now  = (now ^ a[i]);
        //printf("now2 %d\n", now);
        if ( now > ans ) ans = now;
        change(now);
        temp = (now ^ query());
        if ( temp > ans ) ans = temp;
        insert();
    }
    printf("%d\n", ans);


}

int main()
{

    init();
    scanf("%d", &T);
    while ( T-- )
    {
        memset(tree, -1, sizeof(tree));
        //printf("%d\n", tree[1].l);
        input();
        solve();
       // printf("%d\n", v);
    }



    return 0;
}
