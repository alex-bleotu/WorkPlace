#include <iostream>

using namespace std;

int minCif(int x) {
    int min = 10;
    while (x) {
        if (x % 10 < min)
            min = x % 10;
        x /= 10;
    }
    return min;
}

int main() {
    int x, min, value = 1;
    cin >> x;
    x = x < 0 ? -x : x;
    min = minCif(x);
    while (x / value) {
        if (x / value % 10 == min)
            x = x / value / 10 * value + x % value;
        else
            value *= 10;
    }
    cout << x;
}