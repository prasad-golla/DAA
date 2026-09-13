#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;

int maxCrossingSum(const vector<int>& a, int low, int mid, int high) {
    int leftSum = INT_MIN, sum = 0;

    for (int i = mid; i >= low; --i) {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; ++i) {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarraySum(const vector<int>& a, int low, int high) {
    if (low == high)
        return a[low];

    int mid = low + (high - low) / 2;

    int left = maxSubarraySum(a, low, mid);
    int right = maxSubarraySum(a, mid + 1, high);
    int cross = maxCrossingSum(a, low, mid, high);

    return max({left, right, cross});
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements: ";
    for (int& x : a) cin >> x;

    cout << "Maximum subarray sum = "
         << maxSubarraySum(a, 0, n - 1) << '\n';
}