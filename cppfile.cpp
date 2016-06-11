#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="why so serious";

    ofstream writer("neeraj.txt");

    if(!writer)
        cout<<"error"<<endl;
    else
        writer<<s;

    writer.close();

    ofstream writer2("neeraj.txt",ios::app);
        if(!writer2)
            cout<<"error";
        else
        {
            writer2<<"-joker";
            writer2.close();
        }

    char c;

    ifstream reader("neeraj.txt");

    if(!reader)
        cout<<"error";
    else
    {
        for(int j=0;!reader.eof();j++)
        {
         reader.get(c);
            cout<<c;
        }

        reader.close();

    }
    return 0;
}
