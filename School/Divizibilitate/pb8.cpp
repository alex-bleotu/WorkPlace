#include <iostream>

using namespace std;

int cmmdc(int x, int y) {
    while(y != 0)
    {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << x * y / cmmdc(x, y) << "\n" << cmmdc(x, y);
}