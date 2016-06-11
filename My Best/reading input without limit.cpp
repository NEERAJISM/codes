#include <bits/stdc++.h>
using namespace std;
int main(){
    // do not use endl it is slow
    // the two lines below allow a much faster input and output
    // when using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    char c;

    while(cin >> n) // for integer
    {
        cout << n << endl;
    }

    while (getline(cin,s)) // for string
    {
         cout << s << endl;
    }

    while (cin.get(c)) // for character
    {
        cout << c << endl;
    }
    return 0;
}
