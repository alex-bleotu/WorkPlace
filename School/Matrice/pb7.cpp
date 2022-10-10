#include <iostream>
#include <fstream>

using namespace std;

void citire(int a[][100], int &n, int &m) {
    ifstream fin("matrice.in");
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fin >> a[i][j];
}

int primaCif(int x) {
    if (x < 0)
        x = -x;
    while (x > 9)
        x = x / 10;
    return x;
}

void sortare(int a[][100], int n, int m, int col) {
    int aux;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (primaCif(a[i][col]) < primaCif(a[j][col])) {
                aux = a[i][col];
                a[i][col] = a[j][col];
                a[j][col] = aux;
            }
}

void sortareTot(int a[][100], int n, int m) {
    for (int j = 0; j < m; j++)
        sortare(a, n, m, j);
}

void afisare(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int a[100][100], n, m;
    citire(a, n, m);
    sortareTot(a, n, m);
    afisare(a, n, m);
    return 0;
}