#include <iostream>

using namespace std;

int numberOfDivisors(int x) {
    int nr = 1, p = 0;
    while (x % 2 == 0)
        p++, x /= 2;
    if (p)
        nr *= p + 1;
    for (int d = 3; d * d <= x; d += 2) {
        p = 0;
        while (x % d == 0)
            p++, x /= d;
        if (p)
            nr *= p + 1;
    }
    if (x > 1)
        nr *= 2;
    return nr;
}

int main() {
    int x, nrOfDivisors;
    cin >> x;
    nrOfDivisors = numberOfDivisors(x);
    cout << nrOfDivisors * 2 << "\n" << nrOfDivisors;
}