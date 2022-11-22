#include <iostream>

using namespace std;

bool isPrim(int number, int divisor) {
    if (number % divisor == 0)
        return false;
    if (divisor * divisor > number)
        return true;
    return isPrim(number, divisor + 2);
}

bool isPrimComplete(int number) {
    if (number < 2 || number != 2 && number % 2 == 0)
        return false;
    return isPrim(number, 3);
}

int main() {
    int x;
    cin >> x;
    cout << isPrimComplete(x);
}