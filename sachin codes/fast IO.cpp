#include<bits/stdc++.h>
using namespace std;

void read(int &n) {
    register char c;
    n=0;
    while(1) {
        c=getchar();
        if(isdigit(c)) {
            break;
        }
    }
    while(isdigit(c)) {
        n=10*n + (c-'0');
        c=getchar();
    }
}

void write(int &n) {
    int k=-1;
    int buf[11];
    while(n) {
        buf[++k]=n%10;
        n/=10;
    }
    for(int i=k; i>=0; i--) {
        putchar('0'+buf[i]);
    }
    putchar('\n');
}

int main() {
    int n;
    read(n);
    write(n);
}
