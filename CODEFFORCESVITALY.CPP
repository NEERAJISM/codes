#include<iostream>
using namespace std;
char keystring[10000000];
int hashstring[26];
int main()
{
    int n,i,keys=0;
    cin>>n;

    for(i=0;i<2*n-2;i++)
        cin>>keystring[i];

    for(i=0;i<26;i++)
        hashstring[i]=0;

    for(i=0;i<2*n-2;i+=2)
    {
        //for(int j=0;j<26;j++)
        //cout<<hashstring[j]<<" * ";

        //cout<<endl;

         if(((int)keystring[i]-32) != (int)keystring[i+1] )
         {
            if(hashstring[(int)keystring[i+1]-65]>0)
            {
                //cout<<"/*/"<<endl;
                //cout<<hashstring[(int)keystring[i+1]-65]<<" ";
                hashstring[(int)keystring[i+1]-65]--;
                //cout<<hashstring[(int)keystring[i+1]-65];
            }
            else
            {
                keys++;
                hashstring[(int)keystring[i]-97]++;
            }
         }
    }

    cout<<keys;

    return 0;
}
