#include<iostream>
#include<fstream>

using namespace std;
int main()
{ char column[29];
	fstream f("d695.xls", ios::in);
	int n=2;
	for(int i=1;i<=10;i++)
	{
	   f>>i;
	   	
	cout<<column<<"\n";
	
	
		cout<<"hello";
		
}
	
	f.close();
	return 0;
}
