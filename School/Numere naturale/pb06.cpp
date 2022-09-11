#include <iostream>

using namespace std;

int main() {
    int x;
    bool hasSameParity = true;
    cin >> x;
    x = x < 0 ? -x : x;
    do {
        if (x % 10 % 2 != x / 10 % 10 % 2)
            hasSameParity = false;
        x /= 10;
    } while (x > 10);
    cout << hasSameParity;
}