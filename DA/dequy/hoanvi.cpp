#include <bits/stdc++.h>
using namespace std;

#define N 1001

// Khai báo mảng lưu trữ hoán vị và mảng đánh dấu
int A[N];
bool bMark[N];

int k, n;

// In ra một hoán vị
void solution()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Hàm thử tất cả các giá trị có thể cho vị trí k của hoán vị
void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        // Kiểm tra xem giá trị v đã được chọn trước đó chưa
        if (!bMark[v] /*bMark == false*/)
        {
            A[k] = v;        // Chọn giá trị v cho vị trí k
            bMark[v] = true; // Đánh dấu giá trị v đã được chọn

            // Nếu đã điền đủ n phần tử cho hoán vị, in ra hoán vị đó
            if (k == n)
            {
                solution();
            }
            else
            {
                Try(k + 1); // Thử đặt giá trị cho vị trí tiếp theo
            }

            bMark[v] = false; // Bỏ đánh dấu giá trị v để thử các giá trị khác
        }
    }
}

int main()
{
    n = 3; // Số phần tử của hoán vị
    // Khởi tạo mảng đánh dấu
    for (int i = 1; i <= n; i++)
    {
        bMark[i] = false;
    }

    // Bắt đầu thử tất cả các hoán vị
    Try(1);

    return 0;
}
