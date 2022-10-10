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

int oglindit(int x) {
    int ogl = 0, x1 = x;
    while (x1 != 0) {
        ogl = ogl * 10 + x1 % 10;
        x1 = x1 / 10;
    }
    if (ogl == x)
        return 1;
    return 0;
}

int cmmdc(int x, int y) {
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int cmmdcCol(int a[][100], int n, int c) {
    int cm = a[0][c];
    for (int i = 1; i < n; i++)
        cm = cmmdc(cm, a[i][c]);
    return cm;
}

///inserare de coloane
void inserareFata(int a[][100], int n, int &m) {
    for (int j = 0; j < m; j++)
        if (oglindit(a[0][j]) == 1) {
            m++;
            int cm = cmmdcCol(a, j, n);
            for (int c = m - 1; c > j; c--)
                for (int i = 0; i < n; i++)
                    a[i][c] = a[i][c - 1];
            for (int i = 0; i < n; i++)
                a[i][j] = cm;
            j++;

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
    inserareFata(a, n, m);
    afisare(a, n, m);
    return 0;
}