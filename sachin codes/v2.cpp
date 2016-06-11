#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int x,y,n;
	vector <int> a;
	vector <int> :: iterator i;
	a.resize(5);
	cout<<"enter the 5 elements\n";
	for(i=a.begin();i<a.end();i++)
	scanf("%d",i);
	for(i=a.begin();i<a.end();i++)
	printf("%d  ",*i);
	cout<<endl;
	cout<<"enter one more value to insert at position 3\n";
	cin>>x;
	a.insert(a.begin()+2,x);
	cout<<"current size is= ";
	printf("%d\n",a.size());
	cout<<"current elements are\n";
	for(int j=0;j<a.size();j++)
	printf("%d  ",a[j]);
	cout<<"enter a position to erase\n";
	cin>>x;
	a.erase(a.begin()+x);
	cout<<"current size is= ";
	printf("%d\n",a.size());
	cout<<"current elements are\n";
	for(int j=0;j<a.size();j++)
	printf("%d  ",a[j]);
	cout<<"enter one more value\n";
	cin>>x;
	a.push_back(x);
	
	printf("last element is= %d",a.back());
	printf("first element is= %d",a.front());
	n=a.size();
	y=n/2;
	printf("last element is= %d",a.at(y));
	a.pop_back();
	//a.pop_front();                        we cannot do any operation on front directly in vector
	cout<<"current size is= ";
	printf("%d\n",a.size());
	cout<<"current elements are\n";
	for(int j=0;j<a.size();j++)
	printf("%d  ",a[j]);
	cout<<"enter 5 more elements\n";
	for(int j=0;j<5;j++)
	{
		scanf("%d",&x);
		a.push_back(x);
	}
	cout<<"current elements are\n";
	for(int j=0;j<a.size();j++)
	printf("%d  ",a[j]);
	a.clear();
	if(a.empty())
	printf("empty vector\n" );
	cout<<"current size is= ";
	printf("%d\n",a.size());
	
	return 0;
}
