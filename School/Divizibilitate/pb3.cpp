#include <iostream>

using namespace std;

int sumOfDivisors(int x) {
    int sum = x + 1;
    for(int d = 2; d * d <= x; d++)
        if(x % d == 0)
        {
            sum += d;
            if(d * d < x)
                sum += x / d;
        }
    return sum;
}

int main() {
    int x;
    cin >> x;
    cout << sumOfDivisors(x);
}