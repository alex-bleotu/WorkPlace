#include <fstream>
#include <climits>
#include <iostream>

using namespace std;

ifstream fin("bomboane.in");
ofstream file;

struct Number {
    int value;
    int position;
};

Number maxim, minim;

void findMaxAndMin(int n, int arr[]) {
    minim.value = INT_MAX;
    maxim.value = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxim.value)
            maxim.value = arr[i], maxim.position = i;
        if (arr[i] < minim.value)
            minim.value = arr[i], minim.position = i;
    }
}

void change(int average, int arr[]) {
    int value = maxim.value - average;
    if (minim.value + value > average) {
        value = average - arr[minim.position];
        arr[minim.position] = average;
        arr[maxim.position] -= value;
    } else if (maxim.value - value >= average) {
        arr[minim.position] += value;
        arr[maxim.position] -= value;
    } else {
        value = arr[maxim.position] - average;
        arr[minim.position] += value;
        arr[maxim.position] -= value;
    }

    fout << maxim.position + 1 << " " << minim.position + 1 << " " << value << "\n";
}

int main() {
    maxim.value = INT_MIN;
    minim.value = INT_MAX;
    int n, arr[1000], average = 0, nr = 0;

    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> arr[i], average += arr[i];

        if (arr[i] > maxim.value)
            maxim.value = arr[i], maxim.position = i;
        if (arr[i] < minim.value)
            minim.value = arr[i], minim.position = i;
    }

    if (average / n * n != average) {
        fout << -1;
        return 0;
    }

    average /= n;

    while (true) {
        change(average, arr);
        findMaxAndMin(n, arr);
        nr++;
        if (maxim.value == minim.value && maxim.value == average)
            break;
    }
}