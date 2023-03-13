#include <fstream>

#define lli long long int
#define MOD 1999999973

using namespace std;

ifstream cin("lgput.in");
ofstream cout("lgput.out");

lli fastPower(lli base, lli power) {
    lli powerValue = 1;

    while (power) {
        if (power % 2 == 1)
            powerValue = (powerValue * base) % MOD;
`
        base = (base * base) % MOD;
        power /= 2;
    }

    return powerValue;
}

int main() {
    lli base, power;

    cin >> base >> power;

    cout << fastPower(base, power);
}