#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Approach: Two passes.
// First, find the largest element.
// Then, skip all occurrences of the largest and find the next largest.
//
// Time complexity: O(n) — two sequential scans, O(n) + O(n) = O(n).
// Auxiliary space: O(1) — only a fixed number of variables.
int second_largest(vector<int> &arr)
{
    int first = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        first = max(first, arr[i]);
    }
    int ans = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == first)
        {
            continue;
        }
        ans = max(ans, arr[i]);
    }
    if (ans == INT_MIN)
    {
        return -1;
    }
    return ans;
}

// Approach: Single pass.
// Track the largest and second largest distinct values.
// When a new largest appears, move the previous largest to second.
// Otherwise, update second if the value lies between second and first.
//
// Time complexity: O(n) — scan the array once.
// Auxiliary space: O(1) — only a fixed number of variables.
int second_largest_2(vector<int> &arr)
{
    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] < first)
        {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
    {
        return -1;
    }
    return second;
}

int main()
{
    vector<int> arr = {12, 3, 15, 15, 7, 9};

    cout << second_largest(arr) << endl;

    cout << second_largest_2(arr) << endl;

    return 0;
}