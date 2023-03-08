#include <bits/stdc++.h>

using namespace std;

string createBitsArray(string str) {
    string bitsArray;
    int index;

    for (index = 0; index < str.length(); index++) {
        int character = str[index];

        int bitsIndex = 7;
        string aux = "********";
        while (bitsIndex >= 0) {
            aux[bitsIndex] = ((character & 1) + '0');

            character >>= 1;
            bitsIndex--;
        }

        bitsArray.append(aux);
    }

    return bitsArray;
}

void print(string bitsArray, int size) {
    for (int i = 0; i < size; i++) {
        cout << bitsArray[i];
        if ((i + 1) % 8 == 0)
            cout << "";
    }
}

string intToBinary(int n) {
    string binary;
    if (n != 0) {
        while (n) {
            string aux = ((n & 1) == 1 ? "1" : "0");
            binary.append(aux);
            n >>= 1;
        }
    } else
        return "0";

    reverse(binary.begin(), binary.end());

    return binary;
}

void removeDigits(string &bitsArray, int &size, string binaryIndex, size_t foundIndex) {
    bitsArray.replace(foundIndex, binaryIndex.length(), "");
    size -= binaryIndex.length();

    cout << binaryIndex << ", " << foundIndex << ": ";
    print(bitsArray, size);
    cout << "\n";
}

int replaceDigits(string bitsArray, int size) {
    int index = 0;

    while (index < 100) { // :)
        string binaryIndex = intToBinary(index);

        bool firstFound = true, secondFound = true;

        size_t foundIndex = bitsArray.find(binaryIndex);
        if (foundIndex == std::string::npos)
            firstFound = false;
        else
            removeDigits(bitsArray, size, binaryIndex, foundIndex);

        foundIndex = bitsArray.rfind(binaryIndex);
        if (foundIndex == std::string::npos)
            secondFound = false;
        else
            removeDigits(bitsArray, size, binaryIndex, foundIndex);

        if (!firstFound && !secondFound)
            return index - 1;

        index++;
    }
}

int findLastBinary(string s) {
    string bitsArray = createBitsArray(s);
    int size = s.length() * 8;

//    print(bitsArray, size);

    return replaceDigits(bitsArray, size);
}

int main()
{
    string s = "Roses are red.";

    int result = findLastBinary(s);
    cout << "\n\n" << result << "\n";
}