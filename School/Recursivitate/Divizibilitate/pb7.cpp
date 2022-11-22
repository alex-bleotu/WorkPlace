#include <iostream>

using namespace std;

int factori(int number, int divisor, int nrOfFactor) {
    if (number == 1)
        return nrOfFactor;
    if (number % divisor == 0)
        return factori(number / divisor, divisor, nrOfFactor + 1);
    return factori(number, divisor + 2, 0) + nrOfFactor;
}

int factoriComplete(int number) {
    int p = 0;
    while (number % 2 == 0) p++, number /= 2;
    return factori(number, 3, 0) + p;
}

int main() {
    int x;
    cin >> x;
    cout << factoriComplete(x);
}