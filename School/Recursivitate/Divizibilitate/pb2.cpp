#include <iostream>

using namespace std;

int cmmdc(int x, int y) {
    if (y == 0)
        return x;
    return cmmdc(y, x % y);
}

int cif(int x) {
    if (x < 10)
        return x;
    return cmmdc(cif(x / 10), x % 10);
}

int main() {
    int x;
    cin >> x;
    cout << cif(x);
}