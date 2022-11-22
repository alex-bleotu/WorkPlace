#include <iostream>

using namespace std;

int ex2_1(int n, int a) {
    if (n == 0) return 1;
    else return a * ex2_1(n - 1, a);
}

int ex3_1(int n) {
    if (n == 0) return 0;
    if ((n - 1) % 2 == 1) return -(n * n) + ex3_1(n - 1);
    else return (n * n) + ex3_1(n - 1);
}

int ex4_1(int n, int sum, int aux) {
    if (aux == n + 1)
        return 0;
    return sum * aux + ex4_1(n, sum * aux, aux + 1);
}

int ex6_1(int n, int s) {
    if (n == 0) return 1;
    return s * 2 + ex6_1(n - 1, s * 2);
}

int ex7_1(int n, int sum, int aux) {
    if (aux == n + 1)
        return 1;
    return (sum + aux) * ex7_1(n, sum + aux, aux + 1);
}

bool ex3_2(int n) {
    if (n < 10) return (n < 5);
    return (n % 10) && ex3_2(n / 10);
}

bool ex4_2(int n) {
    if (n < 10) return (n % 3 == 0);
    return ((n % 10) % 3 == 0) || ex4_2(n / 10);
}

bool ex5_2(int n, int max) {
    if (n < 10) return (n < max);
    return ((n % 10) < max) && ex5_2(n / 10, n % 10);
}

bool prim(int n) {
    return (n == 2 || n == 3 || n == 5 || n == 7);
}

bool ex6_2(int n, int max) {
    if (n < 10) {
        if (prim(n)) {
            if (n > max) return true;
            else return false;
        }
        return true;
    }
    if (prim(n % 10)) {
        if ((n % 10) > max)
            return ex6_2(n / 10, n % 10);
        else return false;
    }
    return ex6_2(n / 10, max);
}

int ex8_2(int n, int o) {
    if (n == 0)
        return o;
    return ex8_2(n / 10, o * 10 + n % 10);
}

int ex10_2(int n) {
    if (n < 10) return n;
    int c1 = n % 10;
    int c2 = n / 10 % 10;
    if (c1 % 2 == 0 && c2 % 2 == 0) return ex10_2(n / 10) * 100 + ((c1 + c2) / 2) * 10 + c1;
    return ex10_2(n / 10) * 10 + c1;
}

int main() {
    int n;
    cin >> n;
    cout << ex10_2(n);
    return 0;
}