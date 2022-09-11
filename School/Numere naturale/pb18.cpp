#include <iostream>

using namespace std;

int firstDigit(int x) {
    while (x > 9)
        x /= 10;
    return x;
}

int main() {
    int x, digit, value = 1;
    cin >> x;
    x = x < 0 ? -x : x;
    digit = firstDigit(x);
    while (x / value / 10) {
        if (x / value % 10 == x / value / 10 % 10 && x % 10 != digit)
            x = (x / value / 10 * 10 + digit) * value * 10 + x % (value * 10), value *= 10;
        value *= 10;
    }
    cout << x;
}
