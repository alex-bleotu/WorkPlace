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

void inserare(int index) {
    m++;
    for (int j = index; j < m; j++)
        for (int i = 0; i < n; i++)
            matrix[i][j + 1] = matrix[i][j];
    for (int i = 0; i < n; i++)
        matrix[i][index] = 0;
}

void rezolvare() {
    for (int j = 2; j < m + 1; j += 2) {
        inserare(j);
        j++;
    }
}

int main() {
    citire();
    rezolvare();
    afisare();
}