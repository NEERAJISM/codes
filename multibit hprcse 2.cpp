#include <iostream>
//#include <cuda.h>
#include <cmath>
#include <bitset>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

//structure for the input string
	struct ip
	{
    	string s1;
    	string s2;
    	string s3;
    	string s4;
 	  	char d;
	};

	struct ip myip[5000];

	//structure for the trie as an array
	struct trie
	{
		string hop;
		int hoplength;
	};
	struct trie hoparray[5000];


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

int mark[100];
int main()
{

	int n,groupsize,flag=0,i,j,k,address,flag1 = 0;
	string tempip;
	char temphop;

	cout<<"Enter the number of inputs in the table : ";
	scanf("%d",&n);
	groupsize = sqrt(n);

	cout<<"No. of groups: "<<groupsize<<"\nSize of each group(except last one!!!): "<<groupsize<<endl;

	//to find whether it is an perfect root or not
	if(groupsize*groupsize < n)
		flag1 = 1;

    //reading the input from the text file
    ifstream file("nj1.txt");
    if(file.is_open())
    {
        for(int i = 0; i < n; ++i)
        {
            file >> myip[i].s1;
            file >> myip[i].d;
        }
    }

    for(int i=0; i<n ; i++)
    {
        string temp = myip[i].s1;
        int ip_size = temp.size(),part;
        flag = 1;
        for(int  j= 0;j<ip_size ;j++)
        {
            part=0;
            while(temp[j] != '.' && j<ip_size)
            {
                part = part*10 + ((int)temp[j]-(int)'0');
                j++;
            }

            if(flag==1)
                myip[i].s1 = bitset<8> (part).to_string();
            else if(flag == 2)
                myip[i].s2 = bitset<8> (part).to_string();
            else if(flag == 3)
                myip[i].s3 = bitset<8> (part).to_string();
            else if(flag == 4)
                myip[i].s4 = bitset<8> (part).to_string();

            flag++;
        }
    }

    for(int i = 0; i < n; ++i)
        cout<<myip[i].s1<<endl<<myip[i].s2<<endl<<myip[i].s3<<endl<<myip[i].s4<<endl<<endl;

    int inputlength;
    string input,input1,input2,input3,input4;
    cout<<"Enter the ipv4 address: ";
    cin>>input;
    inputlength = input.size();

    string temp = input;
    int ip_size = temp.size(),part;
    flag = 1;

    for(int  j= 0;j<inputlength ;j++)
    {
        part=0;
        while(temp[j] != '.' && j<inputlength)
        {
            part = part*10 + ((int)temp[j]-(int)'0');
            j++;
        }

        if(flag==1)
            input1 = bitset<8> (part).to_string();
        else if(flag == 2)
            input2 = bitset<8> (part).to_string();
        else if(flag == 3)
            input3 = bitset<8> (part).to_string();
        else if(flag == 4)
            input4 = bitset<8> (part).to_string();

        flag++;
    }

//****1st part******************************************total groups will be groupsize+1*************

//reinitialise the hop array
	for(i=0;i<5000;i++)
	{
		hoparray[i].hop ="########";
		hoparray[i].hoplength = 0;
	}

//construct trie array for n-1 groups
    for(i=0;i<groupsize;i++)
    {
        for(j=0;j<groupsize;j++)
    	{
    		tempip = myip[i*groupsize+j].s1;
    		temphop = myip[i*groupsize+j].d;

    		int length = tempip.size(),branch;
    		address = 0;
    		for(k=0;k<length/2;k++)
    		{
    			branch = findbranch(tempip[2*k],tempip[2*k+1]);
    			address = 4*address + branch;

				hoparray[340*i + address].hop[hoparray[340*i + address].hoplength] = temphop;
    		    hoparray[340*i + address].hoplength++;
    		}

    	}
    }

//entering the last group ****using the same i*****
    if(flag1 == 1)
    {
    	for(j=0;j<(n-groupsize*groupsize);j++)
    	{
    		tempip = myip[i*groupsize+j].s1;
    		temphop = myip[i*groupsize+j].d;

    		int length = tempip.size(),branch;
    		address = 0;
    		for(k=0;k<length/2;k++)
    		{
    			branch = findbranch(tempip[2*k],tempip[2*k+1]);
    			address = 4*address + branch;

    			hoparray[340*i + address].hop[hoparray[340*i + address].hoplength] = temphop;
    		    hoparray[340*i + address].hoplength++;
    		}
    	}
    }

    	//searching the input
    int branch;
    i=0;
    address=0;

    for(k=0;k<4;k++)
    {
        branch = findbranch(input1[2*k],input1[2*k+1]);
        address = 4*address + branch;
    }

    for(i=0;i<groupsize+flag1;i++)
    {
        cout<<"for the 1st part the next hop value in group "<<i+1<<" is: "<<hoparray[340*i + address].hop<<endl;

        for(j=0;j<8;j++)
        {
            if(hoparray[340*i + address].hop[j]=='#')
                break;
            else
            {
                mark[(int)hoparray[340*i + address].hop[j]-(int)'A']++;
            }
        }
    }
    cout<<endl;

//****2nd part******************************************total groups will be groupsize+1*************

//reinitialise the hop array
	for(i=0;i<5000;i++)
	{
		hoparray[i].hop ="########";
		hoparray[i].hoplength = 0;
	}

//construct trie array for n-1 groups
    for(i=0;i<groupsize;i++)
    {
        for(j=0;j<groupsize;j++)
    	{
    		tempip = myip[i*groupsize+j].s2;
    		temphop = myip[i*groupsize+j].d;

    		int length = tempip.size(),branch;
    		address = 0;
    		for(k=0;k<length/2;k++)
    		{
    			branch = findbranch(tempip[2*k],tempip[2*k+1]);
    			address = 4*address + branch;

				hoparray[340*i + address].hop[hoparray[340*i + address].hoplength] = temphop;
    		    hoparray[340*i + address].hoplength++;
    		}

    	}
    }

//entering the last group ****using the same i*****
    if(flag1 == 1)
    {
    	for(j=0;j<(n-groupsize*groupsize);j++)
    	{
    		tempip = myip[i*groupsize+j].s2;
    		temphop = myip[i*groupsize+j].d;

    		int length = tempip.size(),branch;
    		address = 0;
    		for(k=0;k<length/2;k++)
    		{
    			branch = findbranch(tempip[2*k],tempip[2*k+1]);
    			address = 4*address + branch;

    			hoparray[340*i + address].hop[hoparray[340*i + address].hoplength] = temphop;
    		    hoparray[340*i + address].hoplength++;
    		}
    	}
    }

    	//searching the input
    branch;
    i=0;
    address=0;

    for(k=0;k<4;k++)
    {
        branch = findbranch(input2[2*k],input2[2*k+1]);
        address = 4*address + branch;
    }

    for(i=0;i<groupsize+flag1;i++)
    {
        cout<<"for the 2nd part the next hop value in group "<<i+1<<" is: "<<hoparray[340*i + address].hop<<endl;

        for(j=0;j<8;j++)
        {
            if(hoparray[340*i + address].hop[j]=='#')
                break;
            else
            {
                mark[(int)hoparray[340*i + address].hop[j]-(int)'A']++;
            }
        }
    }
        cout<<endl;

//****3rd part******************************************total groups will be groupsize+1*************

//reinitialise the hop array
	for(i=0;i<5000;i++)
	{
		hoparray[i].hop ="########";
		hoparray[i].hoplength = 0;
	}

//construct trie array for n-1 groups
    for(i=0;i<groupsize;i++)
    {
        for(j=0;j<groupsize;j++)
    	{
    		tempip = myip[i*groupsize+j].s3;
    		temphop = myip[i*groupsize+j].d;

    		int length = tempip.size(),branch;
    		address = 0;
    		for(k=0;k<length/2;k++)
    		{
    			branch = findbranch(tempip[2*k],tempip[2*k+1]);
    			address = 4*address + branch;

				hoparray[340*i + address].hop[hoparray[340*i + address].hoplength] = temphop;
    		    hoparray[340*i + address].hoplength++;
    		}

    	}
    }

//entering the last group ****using the same i*****
    if(flag1 == 1)
    {
    	for(j=0;j<(n-groupsize*groupsize);j++)
    	{
    		tempip = myip[i*groupsize+j].s3;
    		temphop = myip[i*groupsize+j].d;

    		int length = tempip.size(),branch;
    		address = 0;
    		for(k=0;k<length/2;k++)
    		{
    			branch = findbranch(tempip[2*k],tempip[2*k+1]);
    			address = 4*address + branch;

    			hoparray[340*i + address].hop[hoparray[340*i + address].hoplength] = temphop;
    		    hoparray[340*i + address].hoplength++;
    		}
    	}
    }

    //searching the input
    branch;
    i=0;
    address=0;

    for(k=0;k<4;k++)
    {
        branch = findbranch(input3[2*k],input3[2*k+1]);
        address = 4*address + branch;
    }

    for(i=0;i<groupsize+flag1;i++)
    {
        cout<<"for the 3rd part the next hop value in group "<<i+1<<" is: "<<hoparray[340*i + address].hop<<endl;
        for(j=0;j<8;j++)
        {
            if(hoparray[340*i + address].hop[j]=='#')
                break;
            else
            {
                mark[(int)hoparray[340*i + address].hop[j]-(int)'A']++;
            }
        }
    }
    cout<<endl;


//****4th part******************************************total groups will be groupsize+1*************

//reinitialise the hop array
	for(i=0;i<5000;i++)
	{
		hoparray[i].hop ="########";
		hoparray[i].hoplength = 0;
	}

//construct trie array for n-1 groups
    for(i=0;i<groupsize;i++)
    {
        for(j=0;j<groupsize;j++)
    	{
    		tempip = myip[i*groupsize+j].s4;
    		temphop = myip[i*groupsize+j].d;

    		int length = tempip.size(),branch;
    		address = 0;
    		for(k=0;k<length/2;k++)
    		{
    			branch = findbranch(tempip[2*k],tempip[2*k+1]);
    			address = 4*address + branch;

				hoparray[340*i + address].hop[hoparray[340*i + address].hoplength] = temphop;
    		    hoparray[340*i + address].hoplength++;
    		}

    	}
    }

//entering the last group ****using the same i*****
    if(flag1 == 1)
    {
    	for(j=0;j<(n-groupsize*groupsize);j++)
    	{
    		tempip = myip[i*groupsize+j].s4;
    		temphop = myip[i*groupsize+j].d;

    		int length = tempip.size(),branch;
    		address = 0;
    		for(k=0;k<length/2;k++)
    		{
    			branch = findbranch(tempip[2*k],tempip[2*k+1]);
    			address = 4*address + branch;

    			hoparray[340*i + address].hop[hoparray[340*i + address].hoplength] = temphop;
    		    hoparray[340*i + address].hoplength++;
    		}
    	}
    }

    //searching the input
    branch;
    i=0;
    address=0;

    for(k=0;k<4;k++)
    {
        branch = findbranch(input4[2*k],input4[2*k+1]);
        address = 4*address + branch;
    }

    for(i=0;i<groupsize+flag1;i++)
    {
        cout<<"for the 4th part the next hop value in group "<<i+1<<" is: "<<hoparray[340*i + address].hop<<endl;
        for(j=0;j<8;j++)
        {
            if(hoparray[340*i + address].hop[j]=='#')
                break;
            else
            {
                mark[(int)hoparray[340*i + address].hop[j]-(int)'A']++;
            }
        }
    }
    cout<<endl<<endl;

    cout<<"after intrsecting result from all groups the Longest prefixmatching next hops are : ";

    for(i=0;i<n;i++)
    {
        if(mark[i]==groupsize)
            cout<<(char)(i+65)<<" ";
    }


return 0;
}
