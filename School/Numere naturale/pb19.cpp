#include <iostream>

using namespace std;

int main() {
    int x, value = 1;
    cin >> x;
    x = x < 0 ? -x : x;
    while (x / value / 10) {
        if (x / value % 10 == x / value / 10 % 10)
            x = x / value / 10 * value + x % value;
        else
            value *= 10;
    }
    cout << x;
}