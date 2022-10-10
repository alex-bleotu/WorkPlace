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

int prim(int x) {
    int ok = 1;
    if (x < 2 || x % 2 == 0 && x > 2)
        ok = 0;
    for (int d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            ok = 0;
    return ok;
}

int sortare(int a[][100], int n, int m, int x) {
    int aux;
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (prim(a[i][j]) == 1)
                if (a[x][i] > a[x][j]) {
                    aux = a[x][i];
                    a[x][i] = a[x][j];
                    a[x][j] = aux;
                }
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
    for (int i = 0; i < n; i++)
        sortare(a, n, m, i);
    afisare(a, n, m);
    return 0;
}