#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	int t,n,i,s,vote,hash[104]={0},j,score,l;
	char c[22],v;
	long long int d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			s=0;
		    cin>>c>>v;
			l=strlen(c);
			for(j=0;j<l;j++)
			{
				d=int(c[j])*(pow(7,j));
				s+=d%103;
			}
			s=s%103;
			if(v=='+')
			vote=1;
			else
			vote=-1;
			hash[s]=vote;
		}
		score=0;
		for(i=0;i<104;i++)
		{
			score+=hash[i];
		}
		printf("%d\n",score);
	}
	return 0;
}
