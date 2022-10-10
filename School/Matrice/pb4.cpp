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

int egal(int a[][100], int n, int m, int i) {
    int ok = 1, b = a[i][0];
    for (int j = 1; j < m; j++)
        if (a[i][j] != b)
            ok = 0;
    return ok;
}

int verif(int a[][100], int n, int m) {
    int oki = 0;
    for (int i = 0; i < n; i++)
        if (egal(a, n, m, i) == 1)
            oki = 1;
    return oki;
}

int main() {
    int a[100][100], n, m;
    citire(a, n, m);
    if (verif(a, n, m) == 1)
        cout << "exista";
    else cout << "nu";
    return 0;
}