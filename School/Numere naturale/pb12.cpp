#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<10> frecv;

    int x;
    cin >> x;
    x = x < 0 ? -x : x;
    while (x) {
        if (frecv[x % 10] == 1) {
            cout << 0;
            return 0;
        }
        frecv[x % 10] = 1;
        x /= 10;
    }
    cout << 1;
    return 0;
}