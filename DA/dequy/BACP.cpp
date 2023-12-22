#include <bits/stdc++.h>
using namespace std;

#define MAX_N 16

// Khai báo biến và mảng cần thiết
int c[MAX_N];           // Trọng lượng (hoặc số tín chỉ) của mỗi môn học
int A[MAX_N][MAX_N];    // Ma trận biểu diễn các môn học điều kiện tiên quyết

int x[MAX_N];           // x[i] là kỳ học mà môn học i được phân bổ vào
int n, m;               // Số môn học và số kỳ học

// Kiểm tra xem môn học v có thể được phân vào kỳ học k không
bool check(int v, int k) {
    // Duyệt qua các môn học từ 1 đến k - 1
    for (int i = 1; i <= k - 1; i++) {
        // Nếu môn học i và môn học k cùng được yêu cầu trước một môn học khác
        // thì việc phân bổ môn học này vào kỳ học v không hợp lệ
        if (x[i] == v && A[i][k] == 1) 
            return false;
    }
    return true;  // Trả về true nếu không có vấn đề nào
}

int max_load = INT_MAX;  // Biến lưu giữ trọng lượng lớn nhất của các kỳ học

// Hàm này tính trọng lượng lớn nhất của các kỳ học
void solution() {
    int curr_load = 0;  // Trọng lượng của kỳ học hiện tại
    for (int j = 1; j <= m; j++) {
        int load = 0;
        // Tính tổng trọng lượng của môn học trong kỳ học j
        for (int i = 1; i <= n; i++) {
            if (x[i] == j)
                load += c[i];
        }
        // Cập nhật trọng lượng lớn nhất nếu cần
        curr_load = max(curr_load, load);
    }
    max_load = min(max_load, curr_load);
}

// Hàm quay lui để thử tất cả các khả năng phân bổ môn học vào các kỳ học
void Try(int k) {
    for (int v = 1; v <= m; v++) {
        if (check(v, k)) {  // Kiểm tra xem môn học có thể được phân vào kỳ học v hay không
            x[k] = v;       // Gán kỳ học cho môn học k
            if (k == n) 
                solution();  // Nếu đã phân bổ xong tất cả môn học, tính trọng lượng lớn nhất
            else 
                Try(k + 1);  // Ngược lại, tiếp tục phân bổ môn học tiếp theo
        }
    }
}

int main() {
    // Nhập dữ liệu từ input
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> c[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    // Bắt đầu quá trình quay lui từ môn học đầu tiên
    Try(1);
    
    // In ra trọng lượng lớn nhất tìm được
    cout << max_load << endl;
    return 0;
}
