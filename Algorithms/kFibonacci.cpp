#include <iostream>

#define MOD 666013

using namespace std;

void multiply(int a[][3], int b[][3]) {
    int aux[3][3] = {};

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                aux[i][j] = (aux[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = aux[i][j];
}

int kFib(int power) {
    int fibMatrix[3][3] = {
            {0, 1},
            {1, 1}
    }, solMatrix[3][3] = {
            {0, 1},
            {1, 1}
    };

    power -= 2;

    while (power) {
        if (power % 2 == 1)
            multiply(solMatrix, fibMatrix);

        power /= 2;
        multiply(fibMatrix, fibMatrix);
    }

    return solMatrix[1][1];
}

int main() {
    cout << kFib(7);
}