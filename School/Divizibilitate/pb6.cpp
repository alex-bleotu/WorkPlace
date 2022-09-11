#include <iostream>
#include <climits>
#define MAX_VALUE 2000000

using namespace std;

int prim[MAX_VALUE];

void generation() {
    prim[0] = prim[1] = 1;
    for (int i = 2; i < MAX_VALUE; i++) {
        if (prim[i] == 0)
            for (int j = i + i; j < MAX_VALUE; j += i)
                prim[j] = 1;
    }
}

int main() {
    generation();
    int x;
    cin >> x;
    for (int i = 2; i < x / 2; i++)
        if (x % i == 0 && prim[i] == 0 && prim[x / i] == 0) {
            cout << 1;
            return 0;
        }
    cout << 0;
}