#include <iostream>
using namespace std;
int main()
{
   int A[5] = {0, 1, 2, 3, 4};
   int B[5] = {3, 2, 1, 0, -1};
   int C[5] = {5, 6, 7, 8, 9};
   int i, result;
   cin >> i;

   result = A[B[C[i%5]-5]+1];
   cout << result;

   return 0;
}
