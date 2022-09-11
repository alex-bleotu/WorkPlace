#include <iostream>

using namespace std;

int main() {
    int x, minCif = 10;
    cin >> x;
    x = x < 0 ? -x : 0;
    do {
        int var = x % 10;
        if (var == 2 || var == 3 || var == 5 || var == 7)
            if (var < minCif)
                minCif = var;
        x /= 10;
    } while (x > 0);
    cout << minCif;
}