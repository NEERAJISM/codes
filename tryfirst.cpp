#include <iostream>
//#include <cuda.h>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

int findbranch(char a,char b)
{
	if(a=='0'&&b=='0')
		return 1;
	else if(a=='0'&&b=='1')
		return 2;
	else if(a=='1'&&b=='0')
		return 3;
	else if(a=='1'&&b=='1')
		return 4;
}

int main()
{
	int n,groupsize,flag=0,i,j,k,address;
	string tempip;
	char temphop,hoparray[10000];

	cout<<"Enter the number of inputs in the table : ";
	scanf("%d",&n);
	groupsize = sqrt(n);

	//initialise the hop array for garbage values
	for(i=0;i<=340*groupsize;i++)
        hoparray[i] = '#';

	cout<<"No. of groups: "<<groupsize<<"\nSize of each group: "<<groupsize<<endl;

	//to find whether it is an perfect root or not
	if(groupsize*groupsize < n)
		flag = 1;

	//structure for the input string
	typedef struct ip
	{
    	string  s;
 	  	char d;
	};
	ip myip[10000];

	/*//structure for the trie as an array
	typedef struct triearray
	{
		char hop[10];
		int length = 0;
	};
	triearray trie[10000];*/

    //reading the input from the text file
    ifstream file("nj1.txt");
    if(file.is_open())
    {
        for(int i = 0; i < n; ++i)
        {
            file >> myip[i].s;
            file >> myip[i].d;
        }
    }

    /*for(int i = 0; i < n; ++i)
        cout<<myip[i].d<<" ";*/

    //construct trie for n-1 grups
    for(i=0;i<groupsize-1;i++)
    {
    	for(j=0;j<groupsize;j++)
    	{
    		tempip = myip[i*groupsize+j].s;
    		temphop = myip[i*groupsize+j].d;

    		int length = tempip.size(),branch;
    		address = 0;
    		for(k=0;k<length/2;k++)
    		{
    			branch = findbranch(tempip[2*k],tempip[2*k+1]);
    			address = 4*address + branch;
    		}

    		hoparray[340*i + address] = temphop;
    	}
    }

    for(i=1;i<20;i++)
    	cout<<hoparray[i]<<" ";

    //construct trie for nth group
return 0;
}
