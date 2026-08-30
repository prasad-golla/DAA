#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, T;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target: ";
    cin >> T;

    unordered_set<int> s;

    for (int i = 0; i < n; i++) {

        int required = T - arr[i];

        if (s.find(required) != s.end()) {
            cout << "Yes\n";
            cout << required << " + " << arr[i]
                 << " = " << T << endl;
            return 0;
        }

        s.insert(arr[i]);
    }

    cout << "No\n";

    return 0;
}