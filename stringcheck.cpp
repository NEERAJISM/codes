#include<iostream>
using namespace std;

int main () {

    int m, n, temp;
    cout << " Give integers m and n : " ;
    cin >> m >> n ;
    do{
        if ( m < n)
            n = n - m;
        if (n < m) {
            temp = m;
            m = n;
            n = temp;
        }
        if(m > n)
            cout << "!";
    }
    while (m < n);
    return -1;
}
