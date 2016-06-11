#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,flag,max,zero;
	map<string,int> m;
	map<string, int> :: iterator it;
	string color,color2;
	
	scanf("%d",&t);
	while(t--)
	{
		m.clear();
		
		string front,back,left,right,top,bottom;
		cin>>front>>back>>left>>right>>top>>bottom;
		
		//cout<<front<<back<<left<<right<<top<<bottom<<endl;
		m[front]++;  m[back]++;  m[left]++;  m[right]++;  m[top]++;  m[bottom]++;
		
		max=0; zero=0; flag=0;
		for(it = (m).begin(); it != (m).end(); it++)
		{
			if(it->second>max)
			max=it->second;
			if(it->second==0)
			zero++;
		}
		if(max<=2)
		flag=1;
		else if(max>=5)
		flag=0;
		else if(max==4)
		{
			for(it = (m).begin(); it != (m).end(); it++)
			{
				if(it->second==max)
				color=it->first;
			}
			if(front==color&&back==color&&top==color&&bottom==color)
			flag=1;
			if(front==color&&back==color&&left==color&&right==color)
			flag=1;
			if(left==color&&right==color&&top==color&&bottom==color)
			flag=1;
		}
		else if(max==3)
		{
			if(zero<4)
			{
				for(it = (m).begin(); it != (m).end(); it++)
				{
					if(it->second==max)
					color=it->first;
				}
				if(front==color&&back==color||top==color&&bottom==color||left==color&&right==color)
				flag=1;
			}
			else if(zero==4)
			{
				color="1";
				for(it = (m).begin(); it != (m).end(); it++)
				{
					if(it->second==max)
					{
						if(color=="1")
						color=it->first;
						else
						color2=it->first;
					}
					if(front==color&&back==color||top==color&&bottom==color||left==color&&right==color)
					flag=1;
					if(front==color2&&back==color2||top==color2&&bottom==color2||left==color2&&right==color2)
					flag=1;
				}
			}
		}
		if(flag==1)
		printf("NO\n");
		else
		printf("YES\n");
	}
	return 0;
}
