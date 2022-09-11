#include <iostream>

using namespace std;

int cifSum(int x) {
    int sum = 0;
    while (x > 0)
        sum += x % 10, x /= 10;
    return sum;
}

int main() {
    int x, sumDigit = 0;
    cin >> x;
    x = x < 0 ? -x : x;
    sumDigit = cifSum(x) % 10;
    while (x > 0) {
        if (x % 10 == sumDigit) {
            cout << 1;
            return 0;
        }
        x /= 10;
    }
    cout << 0;
    return 0;
}