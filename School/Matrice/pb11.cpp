#include <iostream>

using namespace std;

int n, m, matrix[100][100];

void citire() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
}

void afisare() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

bool verificare(int index1, int index2) {
    for (int i = 0; i < m; i++) {
        if (matrix[index1][i] != matrix[index2][i])
            return false;
    }
    return true;
}

void stergere(int index) {
    for (int i = index; i < n - 2; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = matrix[i + 2][j];
    n -= 2;
}

void rezolvare() {
    for (int i = 0; i < n - 1; i++)
        if (verificare(i, i + 1)) {
            stergere(i);
            i--;
        }
}

int main() {
    citire();
    rezolvare();
    afisare();
}