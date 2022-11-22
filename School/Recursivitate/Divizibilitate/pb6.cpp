#include <iostream>

using namespace std;

void factori(int number, int divisor, int nrOfFactor) {
    if (number == 1) {
        cout << divisor << " " << nrOfFactor << "\n";
        return;
    }
    if (number % divisor == 0)
        return factori(number / divisor, divisor, nrOfFactor + 1);
    if (nrOfFactor != 0)
        cout << divisor << " " << nrOfFactor << "\n";
    return factori(number, divisor + 2, 0);
}

void factoriComplete(int number) {
    int p = 0;
    if (number % 2 == 0) {
        while (number % 2 == 0) p++, number /= 2;
        cout << 2 << p;
    }
    factori(number, 3, 0);
}

int main() {
    int x;
    cin >> x;
    factoriComplete(x);
}