#include <bits/stdc++.h>
using namespace std;

long long matrixChainMultiplication(const vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

  
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; ++k) {
                long long cost = dp[i][k] + dp[k + 1][j]
                    + 1LL * dims[i] * dims[k + 1] * dims[j + 1];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> dims = {40, 20, 30, 10, 30};

    cout << "Minimum multiplications: "
         << matrixChainMultiplication(dims) << '\n';

    return 0;
}