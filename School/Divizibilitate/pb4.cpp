#include <iostream>

using namespace std;

int sumOfPowers(int x) {
    int sum = 0;
    while (x % 2 == 0)
        p++, x /= 2;
    if (p)
        sum += p;
    for (int d = 3; d * d <= x; d += 2) {
        p = 0;
        while (x % d == 0)
            p++, x /= d;
        if (p)
            sum += p;
    }
    if (x > 1)
        sum++;
    return sum;
}

int main() {
    int x;
    cin >> x;
    cout << sumOfPowers(x);
}