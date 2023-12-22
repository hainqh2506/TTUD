#include <bits/stdc++.h>

// Ma trận để lưu trữ các giá trị đã tính trước đó và giảm độ phức tạp tính toán
int m[100][100];

using namespace std;

// Hàm đệ quy để tính tổ hợp C(k, n)
int C(int k, int n)
{
    // Base case: Các trường hợp cơ bản, khi k bằng 0 hoặc k bằng n, giá trị C(k, n) là 1
    if (k == 0 || k == n)
    {
        m[k][n] = 1;
    }
    else
    {
        // Kiểm tra xem giá trị đã được tính trước đó hay chưa
        if (m[k][n] == -1)
        {
            // Nếu chưa tính, sử dụng đệ quy để tính toán và lưu giá trị vào ma trận
            m[k][n] = C(k - 1, n - 1) + C(k, n - 1);
        }
    }

    // Trả về giá trị đã tính hoặc được tính trước đó
    return m[k][n];
}

int main()
{
    // Khởi tạo ma trận m với giá trị -1 (chưa tính toán) cho mọi phần tử
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            m[i][j] = -1;
        }
    }

    // In ra giá trị của C(5, 12)
    printf("%d", C(5, 12));

    return 0;
}
