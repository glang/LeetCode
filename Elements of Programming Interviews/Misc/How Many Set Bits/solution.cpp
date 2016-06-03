#include <iostream>

using namespace std;

/*
n = 1100
n - 1 = 1011
~(n - 1) = 0100
*/

int numSetBits(int n) {
    int count = 0;

    while (n != 0) {
        n &= (n - 1);
        ++count;
    }

    return count;
}

int main() {
    cout << numSetBits(0) << endl;
    cout << numSetBits(1) << endl;
    cout << numSetBits(2) << endl;
    cout << numSetBits(3) << endl;
    cout << numSetBits(21) << endl;

    //10101
}