#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 +7;



int main() {
    // Đọc dữ liệu đầu vào
    int n;
    int cnt =0;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for(int i = 0; i<=n;i++){
        for(int j = i +1; j <=n;j++){
            if(arr[i] == arr[j] +1 || arr[i] == arr[j] -1){
                cnt++;
            }
        }
    }
    int res;
    res = cnt % MOD;
    // Tính và in ra kết quả

    cout << res << endl;

    return 0;
}

