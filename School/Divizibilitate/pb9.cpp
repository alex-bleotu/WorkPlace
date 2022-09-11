#include <iostream>

using namespace std;

int main() {
    int x, y, z, c = 0;
    cin >> x >> y >> z;
    if (x % 2 == y % 2 == z % 2 == 0)
        c++;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == y % d == z % d == 0)
            c++;
    cout << c;
}