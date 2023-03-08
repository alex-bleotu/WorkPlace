#include <iostream>
#include <cstring>

using namespace std;

void computeLPS(char pat[], int length, int lps[]) {
    int last = 0;
    lps[last] = 0;

    int i = 1;
    while (i < length) {
        if (pat[i] == pat[last])
            lps[i++] = ++last;
        else {
            if (last != 0)
                last = lps[last - 1];
            else
                lps[i++] = 0;
        }
    }
}

void KMP(char txt[], char pat[]) {
    int n = strlen(txt);
    int m = strlen(pat);

    int lps[m];

    computeLPS(pat, m, lps);

    int i = 0, j = 0;
    while (n - i >= m - j) {
        if (txt[i] == pat[j])
            i++, j++;

        if (j == m) {
            cout << "Pattern found at position " << i - j << "\n";
            j = lps[j - 1];
        } else if (i < n && txt[i] != pat[j]){
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char txt[] = "ABABABABCABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";

    KMP(txt, pat);
}