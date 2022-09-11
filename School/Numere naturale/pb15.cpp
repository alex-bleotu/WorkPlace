#include <iostream>

using namespace std;

int main() {
    short frecv[10] = {};

    int x;
    cin >> x;
    x = x < 0 ? -x : x;
    while (x)
        frecv[x % 10]++, x /= 10;
    for (int i = 9; i >= 0; i--)
        while (frecv[i]) {
            cout << i;
            frecv[i]--;
        }
    return 0;
}