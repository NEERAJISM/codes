#include<iostream>
using namespace std;
char s1[100000],s2[100000],s3[100000];
int main()
{
    int n,i,c,j,n1,n2,n3,n4,p,flag,flag2;


    cin>>n;
    while(n--)
    {
        cin>>s1;
        cin>>s2;


        for(i=0;s1[i]!='\0';i++)
           // cout<<s1[i];
            n3=i+1;
        for(i=0;s2[i]!='\0';i++)
           // cout<<s2[i];
            n4=i+1;

        flag2=n4;

        if(n4>n3)
        {
            n4=n3;
            n3=flag2;
        }

        flag2=0;

        //cout<<n3<<" "<<n4<<endl;

        c=0;
        for(i=0;i<n4;i++)
        {
          //  cout<<"/*/*/*1\n";
            n1=(int)s1[i]-48;
            n2=(int)s2[i]-48;

            p=n1+n2+c;
            s3[i]=(char)p%10+48;
            //cout<<s3[i];
            c=p/10;
        }

        for(i;i<n3;i++)
        {
            //cout<<"/*/*/*2\n";
            if(s1[i]!='\0')
            {
                p=(int)s1[i]-48+c;
                s3[i]=(char)p%10+48;
               // cout<<s3[i];
                c=p/10;
            }
            else
            {
                p=(int)s2[i]-48+c;
                s3[i]=(char)p%10+48;
               //cout<<s3[i];
                c=p/10;
            }
        }

        while(c!=0)
        {
            //cout<<"/*/*/*3\n";
            s3[i]=(char)c%10+48;
           // cout<<s3[i];
            c=c/10;
            i++;
        }

       // cout<<endl;


        //for(int j=0;j<i;j++)
         //   cout<<s3[j];
           // cout<<endl;

        for(int j=0;j<i;j++)
            if(s3[j]!='0')
                flag=j;

        for(int j=0;j<i;j++)
            if(s3[j]!='0')
            {
                flag2=j;
                break;
            }

        //cout<<"/*/*/*4\n";

        for(int j=flag2;j<=flag;j++)
                cout<<s3[j];

        cout<<endl;
    }
    return 0;
}
