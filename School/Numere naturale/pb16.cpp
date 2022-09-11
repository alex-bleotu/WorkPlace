#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    x = x < 0 ? -x : x;
    while (x > 99) {
        if (x % 10 > x / 10 % 10 && x / 10 % 10 > x / 100 % 10 || x % 10 < x / 10 % 10 && x / 10 % 10 < x / 100 % 10) {
            cout << 1;
            return 0;
        }
        x /= 10;
    }
    cout << 0;
    return 0;
}