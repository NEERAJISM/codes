#include <iostream>
//#include <cuda.h>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	int n,groupsize,flag=0,i,j;
	cout<<"Enter the number of inputs in the table : ";
	scanf("%d",&n);
	groupsize = sqrt(n);
	if(groupsize*groupsize < n)
		flag = 1;

    typedef struct ip{

        string  s;
        char d;
    };
    ip myip[1000];
    //reading tthe input from the text file
    ifstream file("nj1.txt");
    if(file.is_open())
    {
        for(int i = 0; i < n; ++i)
        {
            file >> myip[i].s;
            file >> myip[i].d;
        }
    }
    for(int i = 0; i < n; ++i)
        cout<<myip[i].s<<" "<<myip[i].d<<endl;

    /*for(i=0;i<groupsize;i++)
    {

    }*/


return 0;
}
