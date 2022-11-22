#include <iostream>

using namespace std;

int factori(int number, int divisor) {
    if (divisor * divisor >= number) {
        if (divisor * divisor == number)
            return divisor;
        return 0;
    }
    if (number % divisor == 0)
        return sumDiv(number / divisor, divisor) + number / divisor + divisor;
    return sumDiv(number, divisor + 2);
}

int factoriComplete(int number) {
    if (number % 2 == 0 && number != 2)
        return sumDiv(number, 3) + 3 + number + number / 2;
    return sumDiv(number, 3) + 1 + number;
}

int main() {
    int x;
    cin >> x;
    cout << sumDivComplete(x);
}