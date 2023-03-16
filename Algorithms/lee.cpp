#include <iostream>
#include <queue>

using namespace std;

int map[105][105];
int mapSizeX, mapSizeY;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

void read() {
    cin >> mapSizeX >> mapSizeY;
    for (int i = 1; i <= mapSizeX; i++)
        for (int j = 1; j <= mapSizeY; j++)
            cin >> map[i][j];

    for (int i = 0; i <= mapSizeX + 1; i++)
        map[i][0] = -1, map[i][mapSizeY + 1] = -1;
    for (int j = 0; j <= mapSizeY + 1; j++)
        map[0][j] = -1, map[mapSizeX + 1][j] = -1;
}

void lee(pair<int, int> startCoords) {
    queue<pair<int, int>> road;
    road.push(startCoords);

    map[startCoords.first][startCoords.second] = 1;

    while (!road.empty()) {
        pair<int, int> coords = road.front();

        for (int k = 0; k < 4; k++) {
            pair<int, int> newCoords = {coords.first + di[k], coords.second + dj[k]};

            if (map[newCoords.first][newCoords.second] == 0) {
                map[newCoords.first][newCoords.second] = map[coords.first][coords.second] + 1;
                road.push(newCoords);
            }
        }
        road.pop();
    }
}

void print() {
    for (int i = 1; i <= mapSizeX; i++, cout << "\n")
        for (int j = 1; j <= mapSizeY; j++)
            cout << map[i][j] << " ";
}

int main() {
    read();

    lee({1, 1});

    print();
}