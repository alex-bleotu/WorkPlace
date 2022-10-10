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

int sumCif(int x) {
    int s = 0;
    do {
        int c = x % 10;
        x = x / 10;
        s = s + c;
    } while (x > 0);
    return s;
}

///functie care verif daca linia l are toate elementele cu s cif para
int verifLin(int a[][100], int l, int m) {
    for (int i = 0; i < m; i++)
        if (sumCif(a[l][i]) % 2 != 0)
            return 0;
    return 1;
}

void stergereLinii(int a[][100], int &n, int &m) {
    for (int i = 0; i < n; i++)
        if (verifLin(a, i, m) == 1) {
            for (int l = i; l < n - 1; l++)
                for (int j = 0; j < m; j++)
                    a[l][j] = a[l + 1][j];
            n--;
            i--;
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
    stergereLinii(a, n, m);
    afisare(a, n, m);
    return 0;
}