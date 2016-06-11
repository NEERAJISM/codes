#include <fstream>
#include<iostream>
#include <string>
#include <string.h>
using namespace std;


int main()
{
    ifstream is("d695.xls");

    string line;
    while (std::getline(is, line))
    {
        const char *begin = line.c_str();

        // strip beyond first comma
        if (const char *end = strchr(begin, ','))
        {
            string column1(begin, end - begin);
            cout << column1 << endl;
        }
    }
    return 0;
}


