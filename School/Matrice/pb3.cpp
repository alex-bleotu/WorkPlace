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

int nrprime(int a[][100], int n, int m, int x) {
    int nr = 0;
    for (int j = 0; j < m; j++)
        if (prim(a[x][j]) == 1)
            nr++;
    return nr;
}

int main() {
    int n, m, a[100][100], maxim, v[100];
    citire(a, n, m);
    maxim = nrprime(a, n, m, 0);
    for (int i = 0; i < n; i++) {
        if (nrprime(a, n, m, i) > maxim)
            maxim = nrprime(a, n, m, i);
        v[i] = nrprime(a, n, m, i);
    }
    if (maxim == 0)
        cout << "nu exista nr prime";
    else {
        for (int i = 0; i < n; i++)
            if (v[i] == maxim)
                cout << i << " ";
    }
    return 0;
}