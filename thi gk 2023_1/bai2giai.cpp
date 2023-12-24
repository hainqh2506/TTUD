#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countWays(vector<int>& numbers, int year) {
    int n = numbers.size();
    int result = 0;

    // Sắp xếp danh sách các số tự nhiên
    sort(numbers.begin(), numbers.end());

    // Duyệt qua tất cả các tập con của danh sách các số tự nhiên
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<int> subset;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(numbers[i]);
                sum += numbers[i];
            }
        }

        // Kiểm tra điều kiện để đổi quà
        if (subset.size() > 0 && sum >= year && sum % 5 == 0) {
            ++result;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int year;
    cin >> year;

    int ways = countWays(numbers, year);
    cout << ways << endl;

    return 0;
}
