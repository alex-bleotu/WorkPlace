#include <iostream>
#include <cstring>

using namespace std;

void computeLPS(char txt[], int length, int lps[]) {
    int i = 1, j = 0;
    lps[j] = j;

    while (i < length) {
        if (txt[i] == txt[j])
            lps[i++] = ++j;
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                lps[i++] = 0;
        }
    }
}

int main() {
    char txt[] = "ABABABABCABABDABACDABABCABAB";
    int length = strlen(txt);

    int lps[1000];

    computeLPS(txt, length, lps);

    for (int i = 0; i < length; i++)
        cout << lps[i] << " ";
}