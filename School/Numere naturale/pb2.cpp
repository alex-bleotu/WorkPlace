#include <iostream>

using namespace std;

int main() {
    int x, sum = 0;
    cin >> x;
    x = x < 0 ? -x : x;
    while (x > 0)
        sum += x % 10, x /= 10;
    cout << sum;
}