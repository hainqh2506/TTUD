#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1000000007;
// The chiu, search ra the
// ma t thay bai 1 dung ma

int countPairs(int n, const vector<int>& arr) {
    unordered_map<int, int> freq;
    long long result = 0;

    for (int i = 0; i < n; ++i) {
        int x = arr[i];
        result = (result + freq[x - 1]) % MOD;
        freq[x]++;
    }

    return static_cast<int>(result);
}

int main() {
    // Đọc dữ liệu đầu vào
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Tính và in ra kết quả
    int result = countPairs(n, arr);
    cout << result << endl;

    return 0;
}
