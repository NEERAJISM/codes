//recursive flow classification algorithm
#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x;
    int y;
};

struct poly
{
    struct point mypoint[100000];
};

struct poly mypoly[2000];

int main()
{

	//initialise lookup table

	struct lt_srcip
	{
		string srcip;
		int beg1;
		int end1;
	};

	lt_srcip mysrcip[7];

	mysrcip[1].srcip = "192.151.10.0/23";
	mysrcip[2].srcip = "192.151.11.74/32";
	mysrcip[3].srcip = "192.151.11.17/32";
	mysrcip[4].srcip = "192.151.11.22/32";
	mysrcip[5].srcip = "192.151.11.41/32";
	mysrcip[6].srcip = "192.151.11.43/32";

	mysrcip[1].beg1 = 1;
	mysrcip[1].end1 = 32;

	mysrcip[2].beg1 = 33;
	mysrcip[2].end1 = 46;

	mysrcip[3].beg1 = 47;
	mysrcip[3].end1 = 59;

	mysrcip[4].beg1 = 60;
	mysrcip[4].end1 = 72;

	mysrcip[5].beg1 = 73;
	mysrcip[5].end1 = 84;

	mysrcip[6].beg1 = 85;
	mysrcip[6].end1 = 100;


	struct lt_dstip
	{
		string dstip;
		int beg2;
		int end2;
	};

	lt_dstip mydstip[8];

	mydstip[1].dstip = "0.0.0.0/5";
	mydstip[2].dstip = "8.0.0.0/6";
	mydstip[3].dstip = "12.0.0.0/7";
	mydstip[4].dstip = "14.0.0.0.0/8";
	mydstip[5].dstip = "16.0.0.0.0/4";
	mydstip[6].dstip = "141.183.0.0/16";
	mydstip[7].dstip = "15.0.120.4/32";

	mydstip[1].beg2 = 1;
	mydstip[1].end2 = 25;

	mydstip[2].beg2 = 26;
	mydstip[2].end2 = 37;

	mydstip[3].beg2 = 38;
	mydstip[3].end2 = 43;

	mydstip[4].beg2 = 44;
	mydstip[4].end2 = 57;

	mydstip[5].beg2 = 58;
	mydstip[5].end2 = 77;

	mydstip[6].beg2 = 78;
	mydstip[6].end2 = 89;

	mydstip[7].beg2 = 90;
	mydstip[7].end2 = 100;

	struct lt_srcport	{
		string srcport;
		int beg3;
		int end3;
	};

	lt_srcport mysrcport[2];

	mysrcport[1].srcport = "0:65535";
	mysrcport[1].beg3 = 1;
	mysrcport[1].end3 = 100;

	struct lt_dstport
	{
		string dstport;
		int beg4;
		int end4;
	};

	lt_dstport mydstport[7];

	mydstport[1].dstport = "0:65535";
	mydstport[1].beg4 = 1;
	mydstport[1].end4 = 17;

	mydstport[2].dstport = "1521:1521";
	mydstport[2].beg4 = 18;
	mydstport[2].end4 = 29;

	mydstport[3].dstport = "1525:1525";
	mydstport[3].beg4 = 30;
	mydstport[3].end4 = 40;

	mydstport[4].dstport = "1526:1526";
	mydstport[4].beg4 = 41;
	mydstport[4].end4 = 48;

	mydstport[5].dstport = "1529:1529";
	mydstport[5].beg4 = 49;
	mydstport[5].end4 = 65;

	mydstport[6].dstport = "1221:1221";
	mydstport[6].beg4 = 66;
	mydstport[6].end4 = 78;

	mydstport[7].dstport = "0:1295";
	mydstport[7].beg4 = 79;
	mydstport[7].end4 = 100;


	struct lt_prtcl
	{
		string prtcl;
		int beg5;
		int end5;
	};

	lt_prtcl myprtcl[5];

	myprtcl[1].prtcl = "0x00/0x00";
	myprtcl[1].beg5  = 1;
	myprtcl[1].end5  = 25;

	myprtcl[2].prtcl = "0x06/0xff";
	myprtcl[2].beg5  = 26;
	myprtcl[2].end5  = 50;

	myprtcl[3].prtcl = "0x11/0xff";
	myprtcl[3].beg5  = 51;
	myprtcl[3].end5  = 75;

	myprtcl[4].prtcl = "0x01/0xff";
	myprtcl[4].beg5  = 76;
	myprtcl[4].end5  = 100;

	cout<<"enter the packet header : \n";
	string sip,dip,spo,dpo,pro;

	cout<<"enter the source ip : ";
	cin>>sip;

	cout<<"enter the destination ip : ";
	cin>>dip;

	cout<<"enter the source port : ";
	cin>>spo;

	cout<<"enter the destination port : ";
	cin>>dpo;

	cout<<"enter the source protocol : ";
	cin>>pro;

	int grp1b,grp1e,grp2b,grp2e,res1b,res1e,res2b = 1,res2e = 100,res3b,res3e;

	for(int i=1 ; i<=6 ;i++)
    {
        if(mysrcip[i].srcip.compare(sip)== 0)
        {
        		grp1b = mysrcip[i].beg1;
        		grp1e = mysrcip[i].end1;
        }
    }

    for(int i=1 ; i<=7 ;i++)
    {
        if(mydstip[i].dstip.compare(dip)==0)
        {
        		grp2b = mydstip[i].beg2;
        		grp2e = mydstip[i].end2;
        }
    }

    int temparray[4] = {grp1b,grp1e,grp2b,grp2e};
    sort(temparray,temparray+4);
    res1b = temparray[1];
    res1e = temparray[2];

    for(int i=1 ; i<=7 ;i++)
    {
        if(mydstport[i].dstport.compare(dpo)==0)
        {
        		grp1b = mydstport[i].beg4;
        		grp1e = mydstport[i].end4;
        }
    }

    for(int i=1 ; i<=4 ;i++)
    {
        if(myprtcl[i].prtcl.compare(pro)==0)
        {
        		grp2b = myprtcl[i].beg5;
        		grp2e = myprtcl[i].end5;
        }
    }

    int temparray2[4] = {grp1b,grp1e,grp2b,grp2e};

    sort(temparray2,temparray2+4);

    res3b = temparray2[1];
    res3e = temparray2[2];

    int temparray3[4] = {res1b,res1e,res2b,res2e};

    sort(temparray3,temparray3+4);

    res1b = temparray3[1];
    res1e = temparray3[2];

    int temparray4[4] = {res1b,res1e,res3b,res3e};

    sort(temparray4,temparray4+4);
    res1b = temparray4[1];
    res1e = temparray4[2];

    cout<<"so the set of rules for which the input packet matches are R-"<<res1b<<" to R-"<<res1e<<endl;
return 0;
}
