
#include <bits/stdc++.h>
#define N 1000005
long long Q = 1e9 + 7;
int a[N];
unsigned int n;
int count = 0;
using namespace std;

void sol()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i]==a[j]+1 || a[i]==a[j]-1){
                count ++;
            }
        }
    }
}

int main()
{
    scanf("%d", n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a[i]);
    }

    return 0;
}