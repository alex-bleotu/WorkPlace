#include <iostream>

using namespace std;

int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }

    int x0, y0;
    int divisor = gcdExtended(b, a % b, x0, y0);

    x = y0;
    y = x0 - (a / b) * y0;

    return divisor;
}

int main() {
    int x, y;

    cout << gcdExtended(12, 15, x, y);
}