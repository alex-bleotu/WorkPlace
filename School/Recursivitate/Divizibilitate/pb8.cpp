#include <iostream>

using namespace std;

int factori(int number, int divisor, int nrOfFactor) {
    if (number == 1)
        return divisor;
    if (number % divisor == 0)
        return factori(number / divisor, divisor, nrOfFactor + 1);
    if (nrOfFactor != 0)
        return factori(number, divisor + 2, 0) * divisor;
    return factori(number, divisor + 2, 0);
}

int factoriComplete(int number) {
    int p = 0;
    while (number % 2 == 0) p++, number /= 2;
    return factori(number, 3, 0) * (p == 0 ? 1 : 2);
}

int main() {
    int x;
    cin >> x;
    cout << factoriComplete(x);
}