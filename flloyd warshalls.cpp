//all pair shortest path (flloyd warshall's)

#include <iostream>
#include <stdlib.h>
using namespace std;
int a[50][50],n;

void flloydwarshalls()
{
  for (int k = 0; k < n; ++k)
  {
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n ; ++j)
      {
        if(a[i][j]>a[i][k] + a[k][j])
          a[i][j] =  a[i][k] + a[k][j];
      }

    }
  }
}

int main()
{
  cout<<"enter the no. of vertices in the graph : ";
  cin>>n;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin>>a[i][j];

    flloydwarshalls();

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
        cout<<a[i][j] <<" ";

      cout<<endl;
    }
return 0;
}
