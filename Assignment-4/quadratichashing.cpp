#include <iostream>
using namespace std;

int main() {
    int size = 10;
    int table[10];

    for (int i = 0; i < size; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;

        int index = key % size;
        int j = 0;

        while (table[(index + j * j) % size] != -1) {
            j++;
        }

        table[(index + j * j) % size] = key;
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < size; i++) {
        cout << i << " : " << table[i] << endl;
    }

    return 0;
}