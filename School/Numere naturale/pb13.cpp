#include <iostream>
#include <bitset>

using namespace std;

int main() {
    bitset<10> frecv;

    string x;
    cin >> x;
    x = x < 0 ? -x : x;
    for (int i = 0; i < x.length(); i++) {
        if (frecv[x[i] - '0'] != 1) {
            frecv[x[i] - '0'] = 1;
            cout << x[i] - '0';
        }
    }
    return 0;
}