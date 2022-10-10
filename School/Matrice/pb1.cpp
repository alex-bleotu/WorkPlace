#include <iostream>
#include <fstream>

using namespace std;
int a[100][100], n, m;

void citire(int a[][100], int &n, int &m) {
    ifstream fin("matrice.in");
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fin >> a[i][j];
}

int verif(int x) {
    int ok = 1;
    while (x > 9) {
        if (x % 10 > x / 10 % 10)
            ok = 0;
        x = x / 10;
    }
    return ok;
}

int suma(int i) {
    int s = 0;
    for (int j = 0; j < m; j++)
        if (verif(a[i][j]) == 1)
            s = s + a[i][j];
    return s;
}

int main() {
    citire(a, n, m);
    for (int i = 0; i < n; i++)
        cout << suma(i) << " ";
    return 0;
}