#include <bits/stdc++.h>
using namespace std;
// Week3 - Linear Integer Equation - coefficent 1
int n, M; // Số phương trình và giá trị M
// int a[20];        // Hệ số của biến x
int x[20]; // Giá trị của biến x
int T, R;  // Tổng và phần còn lại của biểu thức sau khi giải xong các phương trình
int cnt;   // Số lượng giải pháp hợp lệ

void readData()
{
    // Đọc dữ liệu đầu vào
    scanf("%d%d", &n, &M);
    /* for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    } */
}

int check(int v, int k)
{
    // Kiểm tra xem giá trị v của biến x có làm cho phương trình k hợp lệ không
    if (k < n)
        return 1;
    if (T + /* a[n] * */ v == M)
        return 1;
    else
        return 0;
}

void solution()
{
    // In ra giải pháp hợp lệ
    cnt++;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf(" = %d\n", M);
}

void Try(int k)
{
    // Thử tất cả các giá trị cho biến x[k]
    for (int v = 1; v <= (M - T - R); v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            T = T + x[k];
            R = R - x[k];
            if (k == n)
                solution(); // Nếu đã gán giá trị cho tất cả biến thì kiểm tra và in ra giải pháp
            else
                Try(k + 1); // Nếu chưa, thử giá trị cho biến k+1
            T = T - x[k];
            R = R + x[k];
        }
    }
}

int main()
{
    cnt = 0;
    readData();
    T = 0;
    R = 0;
    for (int i = 2; i <= n; i++)
    {
        R = R + x[i];
    }
    Try(1); // Bắt đầu từ biến x[1]
    // printf("%d", cnt); // In ra số lượng giải pháp hợp lệ
    return 0;
}
