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
    int x, cmmdcDigits;
    cin >> x;
    cmmdcDigits = x % 10, x /= 10;
    while (x > 0) {
        cmmdcDigits = cmmdc(cmmdcDigits, x % 10);
        x /= 10;
    }
    cout << cmmdcDigits;
}