#include <bits/stdc++.h>
using namespace std;

int arraytono(int d[],int s3)
{
	int r=0;
	for (int i = 0; i < s3; ++i)
		r = r*10+d[i];

	return r;
}

int sizeofint(int d)
{
	int size=0;

	while(d!=0)
	{
		d=d/10;
		size++;
	}

	return size;
}

int main()
{
	int t,a[1000],b[1000],c[1000],k,s1,s2,i,size,var1,var2,var3,j;
	string s;
	char op;

	cin>>t;

	while(t--)
	{
		cin>>s;
		s1=0;
		s2=0;
		i =0;

		while(1)
		{
		    if(s[i]=='-' || s[i]=='+' || s[i]=='*')
                break;

			a[s1] = s[i]-'0';
			s1++;
			i++;
		}
        //cout<<"*/*/*"<<endl;

		op = s[i];
		i++;
		for(i ; i < s.size() ; i++,s2++)
			b[s2] = s[i]-'0';

//the main operation starts from here

		if(op=='+' || op=='-')
		{
			if(op == '+')
			{
				k=0;
				int temp,carry = 0;

				for (i = s1-1,j=s2-1 ; i>=0 && j>=0 ; i--,j--,k++)
				{
					temp = a[i]+b[j]+carry;						//elements in c[k] are in reverse
					c[k] = temp%10;
					carry = temp/10;
				}

				while(i>=0)
				{
					c[k] = a[i] + carry;
					carry= c[k]/10;
					c[k] =c[k]%10;
					i--;
					k++;
				}

				while(j>=0)
				{
					c[k] = b[j] + carry;
					carry = c[k]/10;
					c[k] = c[k]%10;
					j--;
					k++;
				}

				if(carry>0)
				{
					c[k] = carry;
					k++;
				}
			}
			else
			{
				k=0;
				for(i= s1-1,j=s2-1; i>=0,j>=0 ; i--,j--,k++)
				{
					if(a[i] < b[i])
					{
						a[i]+=10;
						a[i+1]--;
					}

					c[k] = a[i]-b[i];
				}

				while(i>=0)
				{
					c[k] = a[i];
					i--;
					k++;
				}
			}

			size  = k;
			size = size>s1?size:s1;
			size = size>(s2+1)?size:(s2+1);

            var1=size-s1;

			while(var1--)
				cout<<" ";

			for(i=0;i<s1;i++)
				cout<<a[i];

            cout<<endl;

            var2=size - (s2+1);

			while(var2--)
				cout<<" ";

			cout<<op;

			for(i=0;i<s2;i++)
				cout<<b[i];
			cout<<endl;

			var1 = size;

			while(var1--)
				cout<<"-";

			cout<<endl;

            var3 = size - k;
			while(var3--)
				cout<<" ";

			for(i=k-1 ; i>=0 ; i--)
				cout<<c[i];

			cout<<endl<<endl;
		}
	}
return 0;
}
