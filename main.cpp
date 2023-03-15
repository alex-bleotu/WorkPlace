#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>

#define MOD 666013

using namespace std;

ifstream fin("circular.in");
ofstream fout("circular.out");

string blueLetters, redLetters;
int **lettersMap = new int*[27];

void generateLettersMap() {
    for (int i = 0; i <= 13; i++) {
        lettersMap[i] = new int[i + 1];

        for (int j = 0, k = i; j < i + 1; j++, k--)
            lettersMap[i][j] = k;
    }

    for (int i = 14, l = 12; i < 26; i++, l--) {
        lettersMap[i] = new int[i + 1];

        for (int j = 0, k = l; k < 13; j++, k++)
            lettersMap[i][j] = k;
        for (int j = 13 - l, k = 13; k > 0; j++, k--)
            lettersMap[i][j] = k;
    }

    for (int i = 0; i < 26; i++, cout << "\n")
        for (int j = 0; j < i + 1; j++)
            cout << lettersMap[i][j] << " ";
}

int timeBetweenLetters(char a, char b) {
    if (b < a)
        swap(a, b);

    int firstDistance = b - a;
    int secondDistance = 90 - b + a - 65 + 1;

    return firstDistance < secondDistance ? firstDistance : secondDistance;
}

int firstTask() {
    int totalTime = 0;

    totalTime += timeBetweenLetters('A', blueLetters[0]);
    for (int i = 0; i < blueLetters.length() - 1; i++)
        totalTime += timeBetweenLetters(blueLetters[i], blueLetters[i + 1]);

    return totalTime;
}

void secondTask() {
    int totalValues = 0;
    int totalTime = 0;

    for (int i = 0; i < blueLetters.length() - 1; i++) {
        int minim = INT_MAX;
        int values = 0;

        for (int j = 0; j < redLetters.length(); j++) {
            int a = blueLetters[i] - 65, b = redLetters[j] - 65, c = blueLetters[i + 1] - 65;

            int distance1 = b < a ? lettersMap[a][b] : lettersMap[b][a];
            int distance2 = c < b ? lettersMap[b][c] : lettersMap[c][b];

            cout << (char)(a + 65) << " " << (char)(b + 65) << " " << distance1 << "\n";
            cout << (char)(b + 65) << " " << (char)(c + 65) << " " << distance2 << "\n\n";

            if (distance1 + distance2 < minim)
                minim = distance1 + distance2, values = 1;
            else if (distance1 + distance2 == minim)
                values++;
        }

        totalTime += minim;
        totalValues += values;
    }

    fout << totalTime << "\n" << totalValues << "\n";
}

int main() {
    int task;

    fin >> task;
    fin >> blueLetters >> redLetters;

    if (task == 1)
        fout << firstTask();
    else {
        generateLettersMap();

//        secondTask();
    }
}