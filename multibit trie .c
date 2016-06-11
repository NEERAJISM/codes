#include <stdio.h>
//#include <cuda.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

//structure for the input string
	typedef struct ip
	{
    	char s[];
 	  	char d;
	};
	ip myip[10000];

	//structure for the trie as an array
	typedef struct trie
	{
		char hop[]="########";
		int hoplength = 0;
	};
	trie hoparray[10000];

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
	char tempip[];
	char temphop;

	printf("Enter the number of inputs in the table : ");
	scanf("%d",&n);
	groupsize = sqrt(n);

	printf("No. of groups: "%d"\nSize of each group(except last one!!!): %d\n",groupsize,groupsize);

	//to find whether it is an perfect root or not
	if(groupsize*groupsize < n)
		flag = 1;

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

    		int length = strlen(tempip),branch;
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
    if(flag == 1)
    {
    	for(j=0;j<(n-groupsize*groupsize);j++)
    	{
    		tempip = myip[i*groupsize+j].s;
    		temphop = myip[i*groupsize+j].d;

    		int length = strlen(tempip),branch;
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

/*//print the hop array
    for(i=1;i<1000;i++)
    	cout<<hoparray[i].hop<<" ";
    cout<<endl;
*/
    int inputlength;
    char input[];
    printf("Enter the ip value in binary : ");
    scanf("%d",&input);
    inputlength = strlen(input);

//searching the input
    int branch;
    i=0;
    address=0;

    for(k=0;k<inputlength/2;k++)
    {
        branch = findbranch(input[2*k],input[2*k+1]);
        address = 4*address + branch;
    }

    for(i=0;i<groupsize+flag;i++)
        printf("The next hop value in group %d is: %d\n",i,hoparray[340*i + address].hop);

return 0;
}
