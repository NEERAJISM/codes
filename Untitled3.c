#include <iostream>
void swap(int *a, int *b) {
        int *temp;
        temp = a;
        a = b;
        b = temp;
}
int main() {
        int A = 4, B = 6;
        int *Aptr = &A , *Bptr = &B;
        swap(Aptr, Bptr);
        cout << *Aptr << *Bptr;
        return 0;
}
