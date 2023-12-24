// maze  BFS
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
queue<ii> qe;
const int N = 1e4 + 5;
int a[N][N], d[N][N], n, m, r, c, i; // dong i+1 chua  hang thu i cua ma tran
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int solve()
{
    qe.push(ii(r, c));
    a[r][c] = 1;
    d[r][c] = 0;
    while (!qe.empty())
    {
        ii u = qe.front();
        qe.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (x < 1 || x > m || y < 1 || y < n)
            {
                return d[u.first][u.second] + 1;
            }
            if (a[x][y] != 1)
            {
                d[u.first][u.second] + 1;
                qe.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
}
int main()
{
}