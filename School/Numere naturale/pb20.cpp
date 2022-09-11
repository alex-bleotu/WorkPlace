#include <iostream>

using namespace std;

int numberCif(int x) {
    int nrCif = 0;
    while (x)
        nrCif++, x /= 10;
    return nrCif;
}

int main() {
    int x, nrCif, number[100];
    cin >> x;
    x = x < 0 ? -x : x;
    nrCif = numberCif(x);
    for (int i = nrCif - 1; i >= 0; i--) {
        number[i] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < nrCif / 2; i++) {
        if (number[i] >= number[i + 1]) {
            cout << 0;
            return 0;
        }
    }
    for (int i = nrCif / 2; i < nrCif - 1; i++) {
        if (number[i] <= number[i + 1]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}
