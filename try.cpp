

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define pii pair<int,int>

int ar[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ttt,i,j,k,m,n,d,rw,cl,flag = 0,a,b,mn = 0,flag3=0,l,r;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        if(ar[i] == 0)
            mn+=1;
    }

    if(n > 1)
    {
        for(i=0;i<n-1;i++)
        {
            if(ar[i] == 3)
            {
                l=i-1;
                r=i+1;

                while(1)
                {
                    if(l>=0 && ar[l] == 3)
                        l--;
                    else
                        break;
                }

                while(1)
                {
                    if(r<n && ar[r] == 3)
                        r++;
                    else
                        break;
                }
            }

            if((l-1>=0 && r+1<n ) ||l-1>=0)
            {
                    if(ar[l-1] <= 1)
                    {
                        ar[l] = 2;
                        l+=1;
                        while(l<=r)
                        {
                            if(ar[l-1]== 1)
                                ar[l] = 2;
                            else
                                ar[l] = 1;
                            l++;
                        }
                    }
                    else
                    {
                        ar[l] = 1;
                        l+=1;
                        while(l<=r)
                        {
                            if(ar[l-1]== 1)
                                ar[l] = 2;
                            else
                                ar[l] = 1;
                            l++;
                        }
                    }
            }
            else if( r+1<n )
            {
                    if(ar[r+1] <= 1)
                    {
                        ar[r] = 2;
                        r-=1;
                        while(l<=r)
                        {
                            if(ar[r+1]== 1)
                                ar[r] = 2;
                            else
                                ar[r] = 1;
                            r--;
                        }
                    }
                    else
                    {
                        ar[r] = 1;
                        r-=1;
                        while(l<=r)
                        {
                            if(ar[r+1]== 1)
                                ar[r] = 2;
                            else
                                ar[r] = 1;
                            r--;
                        }
                    }
            }
            else
            {
                flag3 = 1;
                break;
            }
        }

                for(i=0;i<n-1;i++)
                {
                    if(ar[i] == 0)
                    continue;
                else if( ar[i+1] == 0)
                    i+=1;
                else
                    {
                        if(ar[i] == ar[i+1])
                        {
                            ar[i+1] = 0;
                            i+=1;
                        }
                    }
                }


                for(i=0;i<n;i++)
                    if(ar[i] == 0)
                    mn+=1;

                cout<<mn;
    }
    else
    {
        if(ar[0] == 0)
            cout<<1;
        else
            cout<<0;
    }

return 0;
}
