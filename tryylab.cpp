#include <iostream>
using namespace std;
int main()
{
  int a[100],n,i,j,mid,item;

    cout<<"enter the no. elements to be searched: ";
    cin>>n;

    for (int i = 0; i < n; ++i)
      cin>>a[i];

    cout<<"enter the  item to be searched : ";
    cin>>item;

    mid = (n-1)/2;

    while(0 < mid && a[mid]!= item)
    {
      if(a[mid] > item)
        i= 0,j=mid - 1;
      else
        i=mid+1,j=n-1;

        mid = (i+j)/2;
    }

    if(a[mid] == item)
      cout<<"item found at position : "<<mid + 1;
    else
      cout<<"item not found ";

    return 0;
}
