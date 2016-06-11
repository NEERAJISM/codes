#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void change(char c[],int a[],int length,int initial_value)
{
	int i;
	for(i=0;i<1002;i++)
	a[i]=initial_value;
	for(i=length-1;i>=0;i--)
	{
		a[i]=int(c[i]-'0');
	}
}

void add_long(int a[],int b[],int r[],int length)
{
	int carry=0,temp,i;
	for(i=length-1;i>=0;i--)
	{
		temp=a[i]+b[i]+carry;
		carry=temp/10;
		r[i+1]=temp%10;
	}
	r[0]=carry;
}

void substract_long(int a[],int b[],int r[],int length)
{
	int i;
	for(i=length-1;i>=0;i--)
	{
		if(a[i]>=b[i])
		r[i]=a[i]-b[i];
		else
		{
			a[i]+=10;
			a[i-1]--;
			r[i]=a[i]-b[i];
		}
	}
}

void multiply_long(int a[],int b[],int m[],int length_a,int length_b)
{
	int i,j,pos=0,carry,temp,x;
	for(i=length_b-1;i>=0;i--)
	{
		carry=0;
		for(j=length_a-1;j>=0;j--)
		{
			temp=(a[j]*b[i])+carry;
			carry=temp/10;
			m[2001+i-length_b-pos]+=temp%10;
			x=m[2001+i-length_b-pos]/10;
			if(x!=0)
			{
				carry+=x;
				m[2001+i-length_b-pos]=m[2001+i-length_b-pos]%10;
			}
		}
		pos++;
	}
}

int main()
{
	char c[1002],d[1002];
	int a[1002],b[1002],r[1003],s[1002],m[2002]={0},p[1002],l,x,i;
	cin>>c>>d;
	int l1=strlen(c),l2=strlen(d);
	if(l1>l2)
	l=l1;
	else
	l=l2;
	change(c,a,l1,0);
	change(d,b,l2,0);
	add_long(a,b,r,l);
	substract_long(a,b,s,l); // assuming that length of a > length of b ;    ,,, a>=b;
	multiply_long(a,b,m,l1,l2);
	cout<<"\n addition result= ";
	for(i=0;i<=l;i++)
	cout<<r[i];
	cout<<"\n substraction result= ";
	for(i=0;i<l;i++)
	cout<<s[i];
	for(i=0;i<2002;i++)
	if(m[i]!=0)
	{
		x=i;
		break;
	}
	cout<<"pos= "<<x;
	cout<<"\n multiplication result= ";
	for(i=x;i<2002;i++)
	cout<<m[i];
	//divide_long(a,b);
	return 0;
}
