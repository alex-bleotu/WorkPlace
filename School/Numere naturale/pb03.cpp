#include <iostream>

using namespace std;

int main() {
    int x, p = 1;
    cin >> x;
    do {
        if (x % 2 == 0)
            p *= x % 10;
        x /= 10;
    } while (x > 0);
    cout << p;
}