#include <iostream>

using namespace std;

bool isPrime(int x) {
    if (x % 2 == 0 && x > 2 || x < 2)
        return false;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}

int main() {
    int x;
    cin >> x;
    cout << isPrime(x);
}