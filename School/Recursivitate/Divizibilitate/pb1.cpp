#include <iostream>

using namespace std;

int cmmdc(int x, int y) {
    if (y == 0)
        return x;
    return cmmdc(y, x % y);
}

int cmmmc(int x, int y) {
    return x * y / cmmdc(x, y);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << cmmdc(x, y) << "\n";
    cout << cmmmc(x, y);
}