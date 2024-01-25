#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minimizeDifference(int n, vector<int>& values) {
    int totalSum = 0;

    // Calculate the total sum of all money bags
    for (int i = 0; i < n; ++i) {
        totalSum += values[i];
    }

    // dp[i][j] represents whether it's possible to achieve a sum j using the first i bags
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

    // Base case: It's always possible to achieve a sum of 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= totalSum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= values[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - values[i - 1]];
            }
        }
    }

    int minDifference = totalSum;

    // Find the minimum difference between two subsets
    for (int j = totalSum / 2; j >= 0; --j) {
        if (dp[n][j]) {
            minDifference = totalSum - 2 * j;
            break;
        }
    }

    return minDifference;
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int result = minimizeDifference(n, values);

    cout << result << endl;

    return 0;
}
