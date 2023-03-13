#include <iostream>

using namespace std;

int fastPower(int base, int power) {
    int powerValue = 1;

    while (power) {
        if (power % 2 == 1)
            powerValue *= base;

        base *= base;
        power /= 2;
    }
}

int main() {
    cout << fastPower(2, 10);
}
