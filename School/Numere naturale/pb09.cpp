#include <iostream>

using namespace std;

int main() {
    int x, newNumber = 0;
    cin >> x;
    x = x < 0 ? -x : x;
    while (x) {
        if (x % 10 % 3 == 0)
            newNumber = newNumber * 10 + x % 10;
        x /= 10;
    }
    while (newNumber) {
        if (newNumber % 10 <= newNumber / 10 % 10) {
            cout << 0;
            return 0;
        }
        newNumber /= 10;
    }
    cout << 1;
    return 0;
}