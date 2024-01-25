#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Read input
    int n;
    cin >> n;

    // Read bag values into a vector
    vector<int> bags(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> bags[i];
    }

    // Sort the bags in non-decreasing order
    sort(bags.begin(), bags.end());

    // Initialize variables for minimum difference
    int minDifference = INT_MAX;

    // Iterate over all possible splits
    for (int i = 0; i < (1 << n); ++i)
    {
        int sum1 = 0, sum2 = 0;

        // Distribute bags based on the bit mask
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                sum1 += bags[j];
            }
            else
            {
                sum2 += bags[j];
            }
        }

        // Update the minimum difference
        minDifference = min(minDifference, abs(sum1 - sum2));
    }

    // Output the result
    cout << minDifference << endl;

    return 0;
}
