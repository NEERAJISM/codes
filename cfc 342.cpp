#include<bits/stdc++.h>
using namespace std;
vector<long long int> v;
long long int cnt;
void computeLPSArray(char *pat, int M, int *lps);
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    computeLPSArray(pat, M, lps);

    int i = 0;
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
        v.push_back((i-j));
        j = lps[j-1];
      }

      else if (i < N && pat[j] != txt[i])
      {
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps);
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    int i;

    lps[0] = 0;
    i = 1;

    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           len = lps[len-1];
         }
         else
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

int main()
{
    char txt[100005],pat[50];

    scanf("%s",txt);
    scanf("%s",pat);

    if(strlen(txt) >=strlen(pat))
    {
        KMPSearch(pat, txt);
        int sz = strlen(pat);
        int nn = v.size(),i = 0,inti,j;
        cnt = 0;

        while(i<nn)
        {
            inti = i;
            i++;
            while(1)
            {
                if((i>=nn) || (v[i] - v[inti] >= sz))
                    break;
                i++;
            }
            cnt++;
        }
    }
   printf("%lld",cnt);
   return 0;
}
