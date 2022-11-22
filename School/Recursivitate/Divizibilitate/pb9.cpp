#include <iostream>

using namespace std;

int factori(int number, int divisor, int powerOfFactor, int maxPower) {
    if (number == 1) {
        if (powerOfFactor != maxPower && maxPower != 0)
            return false;
        return true;
    }
    if (number % divisor == 0)
        return factori(number / divisor, divisor, powerOfFactor + 1, maxPower);
    if (powerOfFactor != 0) {
        if (maxPower == 0)
            maxPower = powerOfFactor;
        else if (powerOfFactor != maxPower)
            return false;
    }
    return factori(number, divisor + 2, 0, maxPower);
}

int factoriComplete(int number) {
    int p = 0;
    while (number % 2 == 0) p++, number /= 2;
    return factori(number, 3, 0, p);
}

int main() {
    int x;
    cin >> x;
    cout << factoriComplete(x);
}