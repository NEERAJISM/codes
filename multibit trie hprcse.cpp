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
	for(i=0;i<=340*(groupsize+1);i++)
        hoparray[i] = '#';

	cout<<"No. of groups: "<<groupsize<<"\nSize of each group(except last one!!!): "<<groupsize<<endl;

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

//**********************************************total groups will be groupsize+1*************

//construct trie array for n-1 grups
    for(i=0;i<groupsize;i++)
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

//entering the last group ****using the same i*****
    if(flag == 1)
    {
    	for(j=0;j<(n-groupsize*groupsize);j++)
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

    int inputlength;
    string input;
    cout<<"Enter the ip value in binary : ";
    cin>>input;

    inputlength = input.size();

//the hop array
    for(i=1;i<1024;i++)
    	cout<<hoparray[i]<<" ";

    cout<<endl;

//searching the input
    int branch;
    i=0;
    address=0;

    for(k=0;k<inputlength/2;k++)
    {
        branch = findbranch(input[2*k],input[2*k+1]);
        address = 4*address + branch;
    }

    cout<<address<<"**"<<endl;

    for(i=0;i<groupsize+1;i++)
    {
        if(hoparray[340*i + address] != '#')
        {
            cout<<"The next hop value at the given ip is : "<<hoparray[340*i + address]<<" "<<340*i+address;
            break;
        }
    }
return 0;
}
