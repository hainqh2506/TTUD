// bai 1 test sdfsd
#include <bits/stdc++.h>
using namespace std;
#define N 1000005
long long Q = 1e9 + 7;

using namespace std;

int main()
{
    int a[N];
    int n;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (a[i] == a[j] + 1 || a[i] == a[j] - 1)
            {
                cnt++;
            }
        }
    }
    int res;
    res = cnt / Q;
    printf("%d", res);

    return 0;
}
