#include <bits/stdc++.h>
using namespace std;
char s[1000006],s1[1000006],s2[1000006];
int main()
{
    int i,j,d,n,flag,flag2;
    scanf("%d",&d);

    while(d--)
    {
        scanf("%s",s);
        n = strlen(s);
        flag = 0;

        if(n%2 == 0)
        {
            strncpy(s1,s,n/2);
            strncpy(s2,s+n/2,n/2);
            if(strcmp(s1,s2) == 0)
                flag = 1;
        }
        else
        {
            i = 0;
            j = n/2+1;
            flag2 = 0;
            while((i<n/2+1) && (j < n))
            {
                if(s[i] != s[j])
                {
                        i++;
                        flag2++;
                }
                else
                {
                    i++;
                    j++;
                }

                if(flag2 > 1)
                    break;
            }

            if(flag2 <=1)
            {
                flag = 1;
            }

            if(flag == 0)
            {
                i = 0;
                j = n/2;
                flag2 = 0;
                while((i<n/2) && (j < n))
                {
                    if(s[i] != s[j])
                    {
                        j++;
                        flag2++;
                    }
                    else
                    {
                        i++;
                        j++;
                    }

                    if(flag2 > 1)
                        break;
                }

                if(flag2 <= 1)
                {
                    flag = 1;
                }
            }
        }

        if(flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
return 0;
}
