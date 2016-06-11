#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int t,n,k,i,j,flag;
    string s,s1;
    scanf("%d",&t);

    while(t--)
    {
        flag =0;
        cin>>s;
        s1 = s;
        n=s.size();

        scanf("%d",&k);

        if(n%2!=0)
            flag=1;
        else
        {
            for(i=0;i<n;i++)
            {
                if(s[i]==')')
                {
                    flag=1;
                    break;
                }
                else if(s[i]=='(')
                {
                    j=i+1;
                    while(s[j]!=')' && j<n)
                        j++;

                    if(j>=n)
                    {
                        flag=1;
                        break;
                    }
                    s[i]='\0';
                    s[j]='\0';
                }
            }

            if(flag!=1)
            {
                for(i=0;i<n;i++)
                {
                    if(s[i]!='\0')
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }

        if(flag==1)
        {
            if(k==1)
            {
                for(i=0;i<n;i++)
                    printf("%c",s1[i]);
                printf("\n");
            }
            else
            {
                printf("-1\n");
            }
        }
        else
        {
            if(k>n)
                printf("-1\n");
            else
            {
                if(k%2!=0)
                {
                    k=k/2+1;
                    if(k<=n/2)
                    {
                        i=n-1;
                        while(i>=0)
                        {
                            if(s1[i]==')')
                            {
                                k--;
                                if(k==0)
                                {
                                    s1[i]='\0';
                                    break;
                                }

                                while(s1[i]==')')
                                    i--;
                                i++;
                            }
                            i--;
                        }
                        if(i<=-1)
                            flag=-1;
                        else
                            for(i=0;i<n;i++)
                            {
                                if(s1[i]!='\0')
                                    printf("%c",s1[i]);
                            }
                    }
                    else
                        flag=-1;
                }
                else
                {
                    k=k/2;

                    if(k<=n/2){
                    i=0;
                    while(i<n)
                    {
                        if(s1[i]=='(')
                        {
                            k--;
                            if(k==0)
                            {
                                s1[i]='\0';
                                break;
                            }

                            while(s1[i]=='(')
                                i++;
                            i--;
                        }
                        i++;
                    }

                    if(i>=n)
                        flag=-1;
                    else
                        for(i=0;i<n;i++)
                        {
                            if(s1[i]!='\0')
                                printf("%c",s1[i]);
                        }
                    }
                    else
                        flag =-1;
                }
                if(flag==-1)
                    cout<<"-1";

                printf("\n");
            }
        }
    }
return 0;
}
