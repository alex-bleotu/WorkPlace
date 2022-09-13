#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << (double)((n + 1) * n * (n + 2) / 3) - n * (n + 1);
}