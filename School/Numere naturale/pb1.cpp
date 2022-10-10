#include <iostream>

using namespace std;

int main() {
    int x, nrCif = 0;
    cin >> x;
    x = x < 0 ? -x : x;
    do {
        nrCif++, x /= 10;
    } while (x > 0);
    cout << nrCif;
}