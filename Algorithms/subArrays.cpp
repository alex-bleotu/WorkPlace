#include <iostream>

using namespace std;

int n, sol[20];

void print(int k) {
    for (int i = 1; i < k; i++)
        cout << sol[i] << " ";
    cout << "\n";
}

void back(int k) {
    if (k > 1)
        print(k);
    for (int i = sol[k - 1] + 1; i <= n; i++) {
        sol[k] = i;
        back(k + 1);
    }
}

int main() {
    cin >> n;

    back(1);
}