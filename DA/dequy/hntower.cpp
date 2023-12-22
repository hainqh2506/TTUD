#include <bits/stdc++.h>
#define N 100
using namespace std;

int cnt;

void move(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cnt += 1;
        printf("step %d: move from %c to %c\n", cnt, A, B);
    }
    else
    {
        move(n - 1, A, C, B);
        move(1, A, B, C);
        move(n - 1, C, B, A);
    }
}

int main()
{
    cnt = 0;
    move(3, 'A', 'B', 'C');
    return 0;
}
