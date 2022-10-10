#include <iostream>

using namespace std;

int main() {
    int x, maxCif = -1;
    cin >> x;
    x = x < 0 ? -x : x;
    do {
        if (x % 10 > maxCif)
            maxCif = x % 10;
    } while(x > 0);
    cout << maxCif;
}