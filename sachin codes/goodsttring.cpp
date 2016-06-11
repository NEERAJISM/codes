#include<iostream>
#include<string.h>
using namespace std;


int func(string s)
{ int g,h;
		for(g=0;g<s.length();g++)
	{
		if(s.at(g)=='a')
		h++;
	}
	return h;
}



int function(string s,int ne)
{
	int l;
	string s1;
	int y=func(s);
	if(y==0)
	{
		return ne;
		
	}
	else
	{
	int x=s.find_first_of('a');
	int i=0;
	while(s.at(x+i)=='a')
	{
		i++;
	};
	if(ne>=i)
	i=ne;
	l=s.length();
	s1=s.substr(x+i+1,(l-x-i-4));
	s=s1;
	function(s,i);
	
	}
}

int main()
{
	string s,s1;
	int j,ne,k,p=0;
	
	cin>>s;
	for(k=0;k<s.length();k++)
	{
		if(s.at(k)=='a')
		p++;
	}
	if(p==0)
	{
		cout<<'a';
	}
	else
	{
	 int ne=function(s,0);
	char c[ne+1];
	for(j=1;j<=(ne+1);j++)
	{
		c[j]='a';
	}
	cout<<c;
}
return 0;
}
