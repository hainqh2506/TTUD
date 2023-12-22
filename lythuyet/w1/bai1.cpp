// CPP
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
    freopen("input.txt", "r", stdin);
    ull a, b;
    cin >> a >> b;
    ull A1 = a / 10;
    ull A2 = a % 10;
    ull B1 = b / 10;
    ull B2 = b % 10;
    ull C = A2 + B2;
    ull D = A1 + B1;
    if (C >= 10)
    {
        C %= 10;
        D += 1;
    }
    if (D == 0)
        cout << C << endl;
    else
        cout << D << C << endl;

    return 0;
}