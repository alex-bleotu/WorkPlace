#include <iostream>
#include <cstring>

using namespace std;

int lcs(char txt1[], char txt2[]) {
    int n = strlen(txt1), m = strlen(txt2);

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (txt1[i] == txt2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    return dp[n][m];
}

int main() {
    char txt1[] = "aaabcd", txt2[] = "agahbdert";

    cout << lcs(txt1, txt2);
}