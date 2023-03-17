#include <iostream>

using namespace std;

int n, sol[100], maxi[100];

void print() {
    for(int i = 1; i <= maxi[n + 1]; i++, cout << " ")
        for(int j = 1; j <= n; j++)
            if(sol[j] == i)
                cout << j;
    cout << "\n";
}
void back(int k) {
    if(k == n + 1) {
        print();
        return;
    }
    for(int i = 1; i <= maxi[k] + 1; i++) {
        sol[k] = i;
        maxi[k + 1] = max (i, maxi[k]);
        back(k + 1);
    }
}

int main() {
    cin >> n;
    back(1);
}