#include <iostream>

using namespace std;

int sizeArr, array[100];

void read(int index) {
    if (index == sizeArr)
        return;
    cin >> array[index];
    read(index + 1);
}

int divisorSum(int number, int divisor) {
    if (divisor * divisor > number)
        return 0;
    if (divisor * divisor == number)
        return divisor;
    if (number % divisor == 0)
        return divisor + number / divisor + divisorSum(number, divisor + 1);
    return divisorSum(number, divisor + 1);
}

bool verify(int number) {
    if (number < 10)
        return true;
    return verify(number / 10) && (number / 10 % 10 < number % 10);
}

bool solve(int index) {
    if (index == sizeArr)
        return false;

    return verify(divisorSum(array[index], 1)) || solve(index + 1);
}


int main() {
    cin >> sizeArr;
    read(0);

    cout << solve(0);
}