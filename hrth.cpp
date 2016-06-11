#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000009

#define fp(i,s,e) for(i=s;i<=e;i++)
#define fm(i,s,e) for(i=s;i>=e;i--)

bool isSubSequence(char str1[], char str2[], int m, int n)
{
    // Base Cases
    if (m == 0) return true;
    if (n == 0) return false;

    // If last characters of two strings are matching
    if (str1[m-1] == str2[n-1])
        return isSubSequence(str1, str2, m-1, n-1);

    // If last characters are not matching
    return isSubSequence(str1, str2, m, n-1);
}

int main()
{
    int ttt,i,j,m,n,d,flag,k,a[10004],cnta,cntb,na,nb,nkl,nkm;
    char kl[5005],km[5005];
    float cnt;
    string s;
    scanf("%d",&ttt);
    while(ttt--)
    {
        cnta = 0;
        cntb = 0;

        cin>>s;
        na = s.length();

        if(na<=3)
        {
            fp(i,0,na-1)
                if(s[i] == 'A')
                    cnta++;
                else
                    cntb++;

            if(cnta == 2)
                printf("A\n");
            else if(cntb == 2)
                printf("B\n");
            else
                printf("-1\n");
        }
        else
        {
            flag = 0;
            i = na -1;
            j = na -2;

            while(j>=0)
            {
                if(s[i] == s[j])
                {
                    if(j == 0)
                    {
                        int fl = 0;
                        for(k=j+1;k<i;k++)
                            if(s[k] == s[j])
                            {
                                fl = 1;
                               break;
                            }

                        if(fl == 0)
                        {
                            printf("%c\n",s[j]);
                            flag = 1;
                            break;
                        }
                    }
                    else if(s[j] == s[j-1])
                    {

                        nkl = 0;
                        for(k=1;k<=n-2;k++,nkl++)
                            kl[nkl] = s[k];

                        nkm = 0;
                        for(k=0;k<=j-1;k++,nkm++)
                            km[nkm] = s[k];

                        if(!isSubSequence(kl,km,nkl, nkm))
                        {
                            for(k=0;k<=j;k++)
                                printf("%c",s[k]);
                            printf("\n");
                            flag = 1;
                            break;
                        }
                    }
                }
                j--;
            }

            if(flag == 0)
            {
                i = na -1;
                j = na -2;

                while(s[i] != s[j] && j>=0)
                    j--;

                i = j;
                j = i-1;


                while(j>=0)
                {
                    if(s[i] == s[j])
                    {
                        if(j == 0)
                        {
                            int fl = 0;
                            for(k=j+1;k<i;k++)
                            if(s[k] == s[j])
                            {
                                fl = 1;
                                break;
                            }


                            if(fl == 0)
                            {
                                printf("%c\n",s[j]);
                                flag = 1;
                                break;
                            }
                        }
                        else if(s[j] == s[j-1])
                        {
                            nkl = 0;
                            for(k=1;k<=n-2;k++,nkl++)
                                kl[nkl] = s[k];

                            nkm = 0;
                            for(k=0;k<=j-1;k++,nkm++)
                                km[nkm] = s[k];

                            if(!isSubSequence(kl,km,nkl, nkm))
                            {
                                for(k=0;k<=j;k++)
                                    printf("%c",s[k]);
                                printf("\n");
                                flag = 1;
                                break;
                            }
                        }
                    }
                    j--;
                }
            }

            if(flag == 0)
                printf("-1\n");
        }


    }
return 0;
}
