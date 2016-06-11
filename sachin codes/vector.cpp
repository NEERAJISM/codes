#include<bits/stdc++.h>
using namespace std;
int main ()
{	vector <int> a(10);
	vector <int> ::iterator i;
	for(i=a.begin();i!=a.end();i++)
	{cin>>*i;
	}
	cout<<"elements are \n";
	for(int k=0;k<a.size();k++)
	{
		cout<<a[k]<<"\t";
	}
	cout<<"enter 1 more";
	int n;
	cin>>n;
	a.push_back(n);
	cout<<"last element is =\t"<<a.back()<<endl;
	cout<<"first element is =\t"<<a.at(0)<<endl;
	a.pop_back();
	for(int j=1;j<=5;j++)
	{
		cout<<"enter again"<<endl;
		cin>>n;
		a.push_back(n);
	}
for(i=a.begin();i!=a.end();i++)
	{cout<<*i<<"\t";
	}
	cout<<endl<<"size is= "<<a.size();	
a.clear();
	if(a.empty())
	cout<<"\n"<<"empty";
	
	return 0;
}
