#include <bits/stdc++.h>
//combination k-n

// Bài toán: Liệt kê tất cả các tổ hợp k phần tử từ tập {1, 2, ..., n}

int k, n;         // Số phần tử cần chọn (k), Số phần tử trong tập (n)
int x[30];        // Mảng lưu trữ tổ hợp
using namespace std;

// Hàm kiểm tra xem giá trị v có thỏa mãn điều kiện cho vị trí thứ i hay không
int check(int v, int i)
{
    return 1; // Mặc định luôn thỏa mãn
}

// Hàm in ra một tổ hợp
void solution()
{
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// Hàm thử giá trị cho phần tử thứ i của tổ hợp
void Try(int i)
{
    for (int v = x[i - 1] + 1; v <= n - k + i; v++)
    {
        if (check(v, i))
        {
            x[i] = v; // Gán giá trị cho phần tử thứ i

            if (i == k)
            {
                // Nếu đã chọn đủ k phần tử, in ra kết quả
                solution();
            }
            else
            {
                // Ngược lại, thử giá trị cho phần tử tiếp theo (tăng i lên 1 và gọi đệ quy)
                Try(i + 1);
            }
        }
    }
}

int main()
{
    // Nhập số phần tử cần chọn (k) và số phần tử trong tập (n)
    scanf("%d%d", &k, &n);

    // Gọi thủ tục Try để bắt đầu quá trình liệt kê tổ hợp
    Try(1);

    return 0;
}
/*Vòng lặp for:

v = x[i - 1] + 1: Bắt đầu vòng lặp với giá trị v là giá trị của phần tử trước đó (tức là x[i - 1]) cộng 1. Điều này giúp đảm bảo rằng ta không lặp lại các giá trị đã chọn trước đó.
v <= n - k + i: Điều kiện lặp để đảm bảo rằng giá trị v không vượt quá giới hạn của tập (tức là n - k + i).
v++: Tăng giá trị v lên sau mỗi lần lặp.
Kiểm tra và thực hiện đệ quy:

if (check(v, i)): Kiểm tra xem giá trị v có thỏa mãn điều kiện (được xác định bởi hàm check) cho vị trí thứ i hay không.
x[i] = v;: Gán giá trị v cho phần tử thứ i.
if (i == k) { ... }: Nếu đã chọn đủ k phần tử, gọi hàm solution để in ra kết quả.
else { Try(i + 1); }: Ngược lại, thử giá trị cho phần tử tiếp theo bằng cách tăng i lên 1 và gọi đệ quy.*/