#include <iostream>

using namespace std;

int main() {
    int x, ration;
    cin >> x;
    x = x < 0 ? -x : x;
    ration = x % 10 - x / 10 % 10;
    x /= 10;
    while (x > 9) {
        if (x % 10 - x / 10 % 10 != ration) {
            cout << 0;
            return 0;
        }
        x /= 10;
    }
    cout << 1;
}