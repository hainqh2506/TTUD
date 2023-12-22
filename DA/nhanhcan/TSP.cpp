#include <bits/stdc++.h>
#define N 30
#define INF 1e9
using namespace std;

int n, m;
int c[N][N]; // Ma trận trọng số của đồ thị
int x[N];    // Lưu trữ đỉnh đã đi qua
int mark[N]; // Đánh dấu các đỉnh đã đi qua
int f;       // Độ dài hiện tại của hành trình
int f_min;   // Độ dài ngắn nhất của hành trình

// Đọc dữ liệu đầu vào
void readData()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = INF;
        }
    }
    for (int k = 1; k <= m; k++)
    {
        int i, j, d;
        scanf("%d%d%d", &i, &j, &d);
        c[i][j] = d;
    }
}

// Cập nhật độ dài ngắn nhất khi tìm thấy hành trình tốt hơn
void updateBest()
{
    if (f + c[x[n]][x[1]] < f_min)
    {
        f_min = f + c[x[n]][x[1]];
    }
}

// Hàm đệ quy thử tất cả các giá trị cho x[k]
void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (mark[v] == 0)
        {
            x[k] = v;
            f = f + c[x[k - 1]][x[k]];
            mark[v] = 1;
            if (k == n)
                updateBest();
            else
            {
                Try(k + 1);
            }
            f = f - c[x[k - 1]][x[k]];
            mark[v] = 0;
        }
    }
}

int main()
{
    readData();
    f = 0;
    f_min = INF;
    for (int v = 1; v <= n; v++)
    {
        mark[v] = 0;
    }
    x[1] = 1;
    mark[1] = 1;
    Try(2);
    printf("%d", f_min);
    return 0;
}
