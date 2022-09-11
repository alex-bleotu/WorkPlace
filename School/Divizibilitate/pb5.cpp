#include <iostream>

using namespace std;

int number(int x) {
    int nr = 1, p = 0;
    while (x % 2 == 0)
        p++, x /= 2;
    if (p)
        nr *= 2;
    for (int d = 3; d * d <= x; d += 2) {
        p = 0;
        while (x % d == 0)
            p++, x /= d;
        if (p)
            nr *= d;
    }
    if (x > 1)
        nr *= x;
    return nr;
}

int main() {
    int x;
    cin >> x;
    cout << number(x);
}