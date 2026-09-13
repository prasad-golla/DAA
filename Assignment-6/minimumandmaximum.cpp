#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, int> findMinMax(const vector<int>& a, int low, int high) {
    if (low == high)
        return {a[low], a[low]};

    if (high == low + 1)
        return {min(a[low], a[high]), max(a[low], a[high])};

    int mid = low + (high - low) / 2;

    auto left = findMinMax(a, low, mid);
    auto right = findMinMax(a, mid + 1, high);

    return {min(left.first, right.first), max(left.second, right.second)};
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements: ";
    for (int& x : a) cin >> x;

    auto result = findMinMax(a, 0, n - 1);

    cout << "Minimum = " << result.first << '\n';
    cout << "Maximum = " << result.second << '\n';
}