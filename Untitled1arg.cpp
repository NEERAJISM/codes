#include<iostream>
using namespace std;
int main(){

   int number1=1, number2;
   while(1)
   {
   cin >> number2;
   switch (number1) {
      case 1:
         cout <<" Happy ";
      case 2:
         if (number2 < 0 )
            cout << " Holidays ";
         if (number2 > 10 && (number2 % 3 == 0) )
            cout << "Birthday ";
         if (number2 > 5 && (number2 % 2 == 0) )
            cout <<"to you ";
      break;
      case 3:
         cout << "Ending ";
      break;
      default:
         cout << " Good luck next time! ";
   }
   }
   return 0;
}

