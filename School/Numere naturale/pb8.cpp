#include <iostream>

using namespace std;

bool check(int x) {
    int aux = x, palindrome  = 0;
    while (x > 9) {
        if (x % 10 != x / 10 % 10)
            return false;
        palindrome = (palindrome * 100 + (x % 10)) * 10 + x % 10;
    }
    return palindrome == aux;
}

int main() {
    int x, aux, palindrome;
    cin >> x;
    x = x < 0 ? -x : x;
    cout << check(x);
}