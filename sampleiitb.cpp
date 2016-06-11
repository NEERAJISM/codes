#include <iostream>
using namespace std;
int main()
{

int i;
int A[20];
int max, min;
for(i=0;i<20;i++)
   A[i]=i;
max = A[0];
min = A[0];
for(i = 0; i <= 20; i++) {
   if(A[i] >= max)
      max = A[i];
   if(A[i] <= min)
      min = A[i];
}

for(i=0;i<20;i++)
   cout<<A[i]<<" ";

   cout<<endl;
cout << "minimum is " << min << endl;
cout << "maximum is " << max << endl;
return 0;
}
