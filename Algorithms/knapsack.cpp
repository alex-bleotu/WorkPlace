#include <iostream>

using namespace std;

pair<int, int> objects[5002];

int solve(int number, int totalWeight) {
    if (number == 0 || totalWeight == 0)
        return 0;

    if (objects[number - 1].first > totalWeight)
        return solve(number - 1, totalWeight);
    else
        return max(objects[number - 1].second +
                   solve(number - 1, totalWeight - objects[number - 1].first),
                   solve(number - 1, totalWeight));
}

int main() {
    int number, totalWeight;

    cin >> number >> totalWeight;
    for (int i = 0; i < number; i++)
        cin >> objects[i].first >> objects[i].second;

    cout << solve(number, totalWeight);
}