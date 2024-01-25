#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int countTriples(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int count = 0;
    int n = arr.size();

    for (int k = n - 1; k >= 0; k--)
    {
        int i = 0;
        int j = k - 1;

        while (i < j)
        {
            if (arr[i] + arr[j] == arr[k])
            {
                count++;
                count %= MOD;
                i++;
                j--;
            }
            else if (arr[i] + arr[j] < arr[k])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = countTriples(arr);
    cout << result << endl;

    return 0;
}
