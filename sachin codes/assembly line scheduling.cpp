#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a1[]={7,9,3,4,8,4};
	int a2[]={8,5,6,4,5,7};
	int t1[]={2,3,1,3,4};
	int t2[]={2,1,2,2,1};
	int e1=2,e2=4,x1=3,x2=2;
	int f1[6],f2[6];
	int l1[6],l2[6];
	int ff,ll;
	f1[0]=e1+a1[0];
	f2[0]=e2+a2[0];
	
	for(int j=1;j<=6;j++)
	{
		if( f1[j-1]+a1[j] <= f2[j-1]+t2[j-1]+a1[j] )
		{
			f1[j]=f1[j-1]+a1[j];
			l1[j]=1;
		}
		else
		{
			f1[j]=f2[j-1]+t2[j-1]+a1[j];
			l1[j]=2;
		}
		
		if( f2[j-1]+a2[j] <= f1[j-1]+t1[j-1]+a2[j] )
		{
			f2[j]=f2[j-1]+a2[j];
			l2[j]=2;
		}
		else
		{
			f2[j]=f1[j-1]+t1[j-1]+a2[j];
			l2[j]=1;
		}
	}
	
	if(f1[5]+x1<=f2[5]+x2)
	{
		ff=f1[5]+x1;
		ll=1;
	}
	else
	{
		ff=f2[5]+x2;
		ll=2;
	}
	
	cout<<"fastest time="<<ff<<"  "<<"exit station="<<ll<<endl;
	
	
	int i=ll;  stack<pair<int,int> > s;
	s.push(make_pair(i,6));
	//cout<<"line="<<i<<"  "<<"at station="<<"6"<<endl;
	for(int j=5;j>=1;j--)
	{
		if(i==1)
		{
			i=l1[j];  s.push(make_pair(i,j));
			//cout<<"line="<<i<<"  "<<"at station="<<j<<endl;
		}
		else
		{
			i=l2[j];   s.push(make_pair(i,j));
			//cout<<"line="<<i<<"  "<<"at station="<<j<<endl;
		}
	}
	
	
	while(!s.empty())
	{
		int l=s.top().first;   int st=s.top().second;
		cout<<"line="<<l<<"   "<<"at station="<<st<<endl;
		s.pop();
	}	
	return 0;
}
