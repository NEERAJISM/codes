#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t,i,j,k;
	string a;
	char c[100000],b[100000];

	scanf("%d",&t);
	while(t--)
	{
		cin>>a;
		j=0;
		k=0;
		for(i=0;i<a.size();i++)
		{
			if((int)a[i]>96 && (int)a[i]<123)
			{
				c[k] = a[i];
				k++;
			}
			else if(a[i]=='(')
			{

			}
			else if(a[i]==')')
			{
				c[k] = b[j-1];
				j--;
				k++;
			}
			else
			{
				b[j] = a[i];
				j++;
			}
		}

		for(i=0;i<k;i++)
			printf("%c",c[i]);

		printf("\n");
	}
}
