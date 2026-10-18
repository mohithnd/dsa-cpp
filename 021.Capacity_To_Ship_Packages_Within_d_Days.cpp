#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Approach: Load packages in their given order until adding the next
// package would exceed the capacity. Then start a new day.
// Return true if all packages can be shipped within d days.
// Assumption: limit >= the heaviest package.
//
// Time complexity: O(n).
// Auxiliary space: O(1).
bool check(vector<int> &arr, int d, long long limit)
{
    int count = 1;
    long long sum = 0;

    for (int i : arr)
    {
        if (i + sum <= limit)
        {
            sum += i;
        }
        else
        {
            count++;
            sum = i;
        }
    }

    return count <= d;
}

// Approach: Try capacities from the heaviest package to the total weight.
// Return the first feasible capacity, which is the minimum answer.
// Assumes a non-empty array of positive weights and d >= 1.
//
// Let R = total weight - heaviest package + 1.
// Time complexity: O(n * R).
// Auxiliary space: O(1).
long long ship_packages(vector<int> &arr, int d)
{
    long long start = *max_element(arr.begin(), arr.end());
    long long end = accumulate(arr.begin(), arr.end(), 0LL);

    for (long long i = start; i <= end; i++)
    {
        if (check(arr, d, i))
        {
            return i;
        }
    }

    return -1;
}

// Approach: Binary-search between the heaviest package and total weight.
// If a capacity works, save it and try smaller capacities.
// Otherwise, increase the capacity.
// Assumes a non-empty array of positive weights and d >= 1.
//
// Let R = total weight - heaviest package + 1.
// Time complexity: O(n * log(R + 1)).
// Auxiliary space: O(1).
long long ship_packages_2(vector<int> &arr, int d)
{
    long long start = *max_element(arr.begin(), arr.end());
    long long end = accumulate(arr.begin(), arr.end(), 0LL);

    long long ans = -1;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        if (check(arr, d, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int d = 2;

    vector<int> arr2 = {9, 8, 10};
    int d2 = 3;

    cout << ship_packages(arr, d) << endl;
    cout << ship_packages(arr2, d2) << endl;

    cout << endl;

    cout << ship_packages_2(arr, d) << endl;
    cout << ship_packages_2(arr2, d2) << endl;

    return 0;
}