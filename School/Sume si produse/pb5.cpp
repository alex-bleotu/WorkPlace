#include <iostream>

using namespace std;

int main() {
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 1; i <= n - 2; i++)
        sum += (double)i / (3 * i + 3);
    cout << sum;
}
