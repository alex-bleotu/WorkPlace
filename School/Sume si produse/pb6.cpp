#include <iostream>

using namespace std;

long long arr[100];

void generate(int n) {
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + i;
}

int main() {
    int n, p = 1;
    cin >> n;
    generate(n);
    for (int i = 2; i <= n; i++)
        p *= arr[i];
    cout << p;
}
