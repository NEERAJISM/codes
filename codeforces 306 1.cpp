#include <iostream>
using namespace std;
int main()
{
	string s;
	int i,ja=0,kb =0,n,flag_a=0,flag_b=0,corda[100000],cordb[100000],i1;

	cin>>s;
	n= s.size();

	if(n < 4 )
		cout<<"NO"<<endl;
	else
	{
		for(i = 0 ;i<n-1 ;i++ )
		{
			if((s[i]=='A' && s[i+1] == 'B') || (s[i]=='B' && s[i+1] == 'A'))
			{
				if(s[i]=='A')
				{
					corda[ja] = i;
					ja++;
				}
				else
				{
					cordb[kb] = i;
					kb++;
				}
			}
		}

        for(i=0 ;i< ja ;i++)
        {
            if(flag_a == 1)
                break;

        	for(i1=0 ; i1<kb ; i1++)
        	{
        		if(corda[i]-cordb[i1] > 1 || corda[i]-cordb[i1] < -1 )
        			{
        			    cout<<"YES"<<endl;
        			    flag_a =1;
        			    break;
        			}
        	}
        }

        if(flag_a == 0)
        	cout<<"NO"<<endl;

	}
return 0;
}
