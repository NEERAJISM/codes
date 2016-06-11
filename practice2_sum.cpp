#include <iostream>
using namespace std;

// Please write your code, within the "BEGIN-END" blocks given below.
// A "BEGIN-END" block is identified as follows :
//
// "//// BEGIN: Some string DONT_ERASE_xx_yy"
//
//
// "//// END: Some other string DONT_ERASE_xx_yy"
//
// where "xx" is the block number and "yy" is the
// marks allocated for the block
//
// The FIRST block (BLOCK 1 i.e. DONT_ERASE_01_0) carries 0 marks and
// is a placeholder for your personal information.
//
// WARNING :
// (1) Do NOT write any cout or cin statements
// (2) Do NOT delete or modify the existing code i.e. main function, comments, blocks, etc.
// (3) Write your code in between BEGIN and END of the respective blocks only
// (4) Do NOT rename the .cpp file


//// ---------------------------------------------------------------------------
//// BEGIN: Fill your details as comments below DONT_ERASE_01_0
//// Name: Neeraj Patidar
////
//// END: Fill your details as comments above DONT_ERASE_01_0
//// ---------------------------------------------------------------------------



int main()
{
    //Sum of squares of digits of the number
    int sqdNumber,sqdNumber_result;
    cout << "Enter a number" << endl;
    cin >> sqdNumber;

//// ---------------------------------------------------------------------------
//// BEGIN: Write code to calculate sum of square of the number  (marks = 1) DONT_ERASE_02_01
//// Store the computed (sum of the squares of the digits) in 'sqdNumber_result'
    int a;
    sqdNumber_result =0;

    while(sqdNumber!=0)
    {
        a=sqdNumber%10;
        sqdNumber_result=sqdNumber_result+a*a;
        sqdNumber=sqdNumber/10;
    }

//// END: Code to calculate sum of square of the number option DONT_ERASE_02_01
//// ---------------------------------------------------------------------------

    cout << "sum of the squares of the digits of the number 'sqdNumber' is " << sqdNumber_result << endl;

    return 0;
}
