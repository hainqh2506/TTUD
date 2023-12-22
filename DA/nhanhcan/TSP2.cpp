#include <bits/stdc++.h>
#define N 21
#define INF 1e9
using namespace std;
//bai w3 tren lop lt
int n;
int c[N][N];
int x[N];
int mark[N];
int f = 0;
int f_min = INF;

void readData() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
}

bool canGo(int u, int v) {
    return c[u][v] != 0 && mark[v] == 0;
}

void Try(int k) {
    for (int v = 2; v <= n; v++) {
        if (canGo(x[k-1], v)) {
            x[k] = v;
            mark[v] = 1;
            f += c[x[k-1]][v];

            // Cắt nhánh nếu độ dài hành trình hiện tại vượt quá f_min
            if (f <= f_min) {
                if (k == n) {
                    if (c[x[n]][1] != 0 && f + c[x[n]][1] < f_min)
                        f_min = f + c[x[n]][1];
                } else {
                    Try(k + 1);
                }
            }

            f -= c[x[k-1]][v];
            mark[v] = 0;
        }
    }
}

int main() {
    readData();
    x[1] = 1;
    mark[1] = 1;
    Try(2);
    printf("%d\n", f_min);
    return 0;
}
