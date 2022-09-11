#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<10> frecv;

    int x;
    cin >> x;
    x = x < 0 ? -x : x;
    while (x)
        frecv[x % 10] = 1, x /= 10;
    for (int i = 9; i >= 0; i--)
        if (frecv[i] == 1)
            cout << i;
    return 0;
}