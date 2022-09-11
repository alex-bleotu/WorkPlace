#include <iostream>

using namespace std;

int lastOddDigit(int x) {
    while(x) {
        if(x % 10 % 2) {
            return x % 10;
        }
        x /= 10;
    }
    return -1;
}

int main() {
    int x, value = 1, lastDigit;
    cin >> x;
    x = x < 0 ? -x : x;
    lastDigit = lastOddDigit(x);
    while (x / value) {
        if (x / value % 2 == 0)
            x = (x / value / 10 * 10 + lastDigit) * value + x % value;
        value *= 10;
    }
    cout << x;
}