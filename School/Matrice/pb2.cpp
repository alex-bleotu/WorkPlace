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

int maxim(int a[][100], int n, int m, int j) {
    int maxim = a[0][j];
    for (int i = 1; i < n; i++)
        if (a[i][j] > maxim)
            maxim = a[i][j];
    return maxim;
}

int verif(int a[][100], int n, int m, int j) {
    if (maxim(a, n, m, j) == a[0][j]) {
        int aux = maxim(a, n, m, j);
        for (int i = 1; i < n; i++)
            a[i][j] = aux * aux;
    }
}

int main() {
    int a[100][100], n, m;
    citire(a, n, m);
    for (int j = 0; j < m; j++)
        verif(a, n, m, j);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}