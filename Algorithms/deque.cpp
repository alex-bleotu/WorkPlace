#include <iostream>
#include <deque>

using namespace std;

int arr[5000002];

int main() {
    int n, k;
    long long sum = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    deque<int> sequence;

    for (int i = 0; i < n; i++) {
        while (!sequence.empty() && arr[i] <= arr[sequence.back()])
            sequence.pop_back();

        sequence.push_back(i);

        if (sequence.front() == i - k)
            sequence.pop_front();

        if (i >= k - 1)
            sum += 1LL * arr[sequence.front()];
    }

    cout << sum;
}