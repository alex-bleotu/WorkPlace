#include <iostream>

using namespace std;

int n, length;
int sol[1001];

void print() {
    for (int i = 1; i <= length; i++)
        cout << sol[i] << " ";
    cout << "\n";
}

void back(int k) {
    for (int i = sol[k - 1] + 1; i <= n; i++) {
        sol[k] = i;

        if (k == length)
            print();
        else
            back(k + 1);
    }
}

int main() {
    cin >> n >> length;

    back(1);
}