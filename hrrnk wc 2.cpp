    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        int i,j,n,ttt,a,b,k,cost,index,flag,len,lll,val;
        char s[30004];
        scanf("%d",&ttt);
        while(ttt--)
        {
            scanf("%d%d%d",&n,&a,&b);
            scanf("%s",s);
            cost = a;
            i = 0;
            k = 0;
            val = 0;
            lll = 1;

            if(n>1)
            {
                while(lll<n)
                {
                    val = 0;
                    for(i=0;i<lll;i++)
                    {
                        j = i;
                        len = 0;
                        k = lll;
                        while(s[j] == s[k])
                        {
                            j++;
                            k++;
                            len++;

                            if((k>=n) || (j>=lll))
                                break;
                        }

                        if(len > val)
                            val = len;

                        if((k>=n) || (j >=lll))
                                break;
                    }

                    if(val == 0)
                    {
                        cost+=a;
                        lll++;
                    }
                    else
                    {
                        if(b < (val*a))
                        {
                            lll+=val;
                            cost+=b;
                        }
                        else
                        {
                            cost+=a;
                            lll+=1;
                        }
                    }
                }
            }
            printf("%d\n",cost);
        }
        return 0;
    }
