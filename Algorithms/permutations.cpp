#include <iostream>

using namespace std;

int n;
int sol[100], frecv[100];

void print() {
    for (int i = 0; i < n; i++)
        cout << sol[i] << " ";
    cout << "\n";
}

void back(int k) {
    if (k == n) {
        print();
        return;
    }
    for (int i = 0; i < n; i++)
        if (frecv[i] == 0) {
            frecv[i] = 1;
            sol[k] = i + 1;

            back(k + 1);

            frecv[i] = 0;
        }
}

int main() {
    cin >> n;

    back(0);
}