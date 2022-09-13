#include <iostream>

using namespace std;

int pow(int base, int power)
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
    int base, power;
    cin >> base >> power;
    cout << pow(base, power);
}