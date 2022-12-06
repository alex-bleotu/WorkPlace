#include <iostream>

using namespace std;

int sizeArr, array[100];

void read(int index) {
    if (index == sizeArr)
        return;
    cin >> array[index];
    read(index + 1);
}

bool verify(int number) {
    if (number < 10)
        return true;
    return verify(number / 10) && (number / 10 == number % 10);
}

int solve(int index) {
    if (index == sizeArr)
        return 0;
    return solve(index + 1) + verify(array[index]);
}


int main() {
    cin >> sizeArr;
    read(0);

    cout << solve(0);
}