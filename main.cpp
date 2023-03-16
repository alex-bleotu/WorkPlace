#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("alinieri.in");
ofstream fout("alinieri.out");

int main() {
    int planetCount, minimAlign, days;
    int planetsPosition[182] = {};
    int simplifiedSpin = 180;

    fin >> planetCount >> minimAlign >> days;
    for (int i = 0; i < planetCount; i++) {
        int x;
        fin >> x;
        planetsPosition[x % simplifiedSpin]++;
    }

    int planetsAligned = 0, totalPlanetsAligned = 0;
    int restOfDays = days % simplifiedSpin;

    for (int i = 0; i < 180; i++) {
        int currentAlignment[182] = {};

        for (int j = 0; j < 180; j++)
            currentAlignment[(j * (i + 1)) % simplifiedSpin] += planetsPosition[j];

        int counter = 0;
        for (int j = 0; j < 180; j++)
            counter += (currentAlignment[j] >= minimAlign);

        planetsAligned += counter;

        if (i < restOfDays)
            totalPlanetsAligned += counter;
    }

    totalPlanetsAligned += planetsAligned * (days / 180);

    fout << totalPlanetsAligned;
}