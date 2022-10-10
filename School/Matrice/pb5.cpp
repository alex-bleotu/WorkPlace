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

int ogl(int x) {
    int ogl = 0;
    while (x != 0) {
        ogl = ogl * 10 + x % 10;
        x = x / 10;
    }
    if (x == ogl)
        return 1;
}

int ok(int a[][100], int n, int m, int j) {
    int ok = 0;
    for (int i = 0; i < n; i++)
        if (ogl(a[i][j]) == 1)
            ok = 1;
}

int verif(int a[][100], int n, int m) {
    int oki = 0;
    for (int j = 0; j < m; j++)
        if (ok(a, n, m, j) == 1)
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