#include <iostream>

using namespace std;

int nrDiv(int number, int divisor) {
    if (divisor * divisor >= number) {
        if (divisor * divisor == number)
            return 1;
        return 0;
    }
    if (number % divisor == 0)
        return nrDiv(number / divisor, divisor) + 2;
    return nrDiv(number, divisor + 2);
}

int nrDivComplete(int number) {
    if (number % 2 == 0 && number != 2)
        return nrDiv(number, 3) + 4;
    return nrDiv(number, 3) + 2;
}

int main() {
    int x;
    cin >> x;
    cout << nrDivComplete(x);
}