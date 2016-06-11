#include <iostream>
using namespace std;
int main()
{
    int t,n,i;
    string a,b;
    char res[100005];
    scanf("%d",&t);

    while(t--)
    {
        cin>>a>>b;
        n = a.length();

        for(i=0;i<n;i++)
        {
            if(a[i] == b[i])
            {
                if(a[i] == 'W')
                    res[i] = 'B';
                else
                    res[i] = 'W';
            }
            else
                res[i] = 'B';
        }


    }

}
