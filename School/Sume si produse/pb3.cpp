#include <iostream>
#include <math.h>

using namespace std;

int myPow(int base, int power)
{
    int result = 1;
    for(int i = 1 ; i <= power ; i <<= 1)
    {
        if((power & i))
            result *= base;
        base = base * base;
    }
    return result;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    delta = sqrt(delta);
    double x1 = (-b + delta) / 2 * a;
    double x2 = (-b - delta) / 2 * a;

    for (int i = 1; i <= n; i++) {
        cout << myPow(x1, i) + myPow(x2, i) << "\n";
    }
}