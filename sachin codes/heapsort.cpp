#include<iostream>
#include<stdio.h>
using namespace std;

void svap(int *a,int *b)
{
 int t;
 t=*a;
 *a=*b;
 *b=t;
}

void maxheapify(int a[],int n,int idx)
{
 int largest=idx,l=(2*idx)+1,R=(2*idx)+2;
 if(a[l]>a[largest] && l<n)
 largest=l;
 if(a[R]>a[largest] && R<n)
 largest=R;
 if(largest!=idx)
 {
  svap(&a[largest],&a[idx]);
  maxheapify(a,n,largest);
 }
}

void heapsort(int a[],int n)
{
 int i;
 for(i=(n/2)-1;i>=0;i--)
 {
  maxheapify(a,n,i);
 }

 int m=n;
 while(m>1)
 {
  svap(&a[0],&a[m-1]);
  m--;
  maxheapify(a,m,0);
 }
}
  void print(int a[],int n)
{
cout<<"current sequence of elements are \n";
 for(int i=0;i<n;i++)
 {
  cout<<a[i]<<"  ";
 }
 cout<<"\n";
}

int main()
{
 int a[100],n;
 cout<<"enter the size\n";
 cin>>n;
 cout<<"enter the elements of array\n";
 for(int j=0;j<n;j++)
 cin>>a[j];
 print(a,n);
 heapsort(a,n);
 print(a,n);
 return 0;
}
