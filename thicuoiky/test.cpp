#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Treasure {
    int x, y, gold;
};

bool compareTreasures(const Treasure& a, const Treasure& b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int main() {
    int n;
    cin >> n;

    vector<Treasure> treasures(n);
    vector<int> dp(n);

    for (int i = 0; i < n; ++i) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].gold;
    }

    // Sort treasures based on x and y coordinates
    sort(treasures.begin(), treasures.end(), compareTreasures);

    // Dynamic programming to find the maximum gold
    for (int i = 0; i < n; ++i) {
        dp[i] = treasures[i].gold;

        for (int j = 0; j < i; ++j) {
            if (treasures[i].x >= treasures[j].x && treasures[i].y >= treasures[j].y) {
                dp[i] = max(dp[i], dp[j] + treasures[i].gold);
            }
        }
    }

    // Find the maximum gold among all treasures
    int maxGold = *max_element(dp.begin(), dp.end());

    cout << maxGold << endl;

    return 0;
}
