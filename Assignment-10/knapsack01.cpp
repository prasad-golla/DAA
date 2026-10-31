#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n + 1), value(n + 1);

    cout << "Enter the weight and value of each item:\n";
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

   
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
           
            dp[i][w] = dp[i - 1][w];

           
            if (weight[i] <= w) {
                dp[i][w] = max(dp[i][w],
                               value[i] + dp[i - 1][w - weight[i]]);
            }
        }
    }

    cout << "Maximum value in knapsack = " << dp[n][capacity] << endl;

    return 0;
}