#include <iostream>
using namespace std;
int main(){
   for(int i = 0; i < 10; ++i) {
      cout << "*";
      int j = 0;
      while(j++ < 2*i) {
         cout << "+";
      }
      cout << "*" << endl;
   }
   return 0;
}
