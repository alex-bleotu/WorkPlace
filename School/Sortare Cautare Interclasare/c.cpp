#include <iostream>

using namespace std;

struct Number {
    int value;
    int minDigit;
    int maxDigit;

    void calculateDigits() {
        int min = 10, max = -1, auxValue = value;
        while (auxValue) {
            if (auxValue % 10 < min)
                min = auxValue % 10;
            if (auxValue % 10 > max)
                max = auxValue % 10;
            auxValue /= 10;
        }
        minDigit = min;
        maxDigit = max;
    }
};

bool comp(Number nr1, Number nr2) {
    if (nr1.minDigit != nr2.minDigit)
        return nr1.minDigit < nr2.minDigit;
    else if (nr1.maxDigit != nr2.maxDigit)
        return nr1.minDigit + nr1.maxDigit < nr2.minDigit + nr2.maxDigit;
    else
        return nr1.value < nr2.value;
}

int main() {
    Number array[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> array[i].value;
        array[i].calculateDigits();
    }

    sort(array, array + n, comp);

    for (int i = 0; i < n; i++)
        cout << array[i].value << " ";
}