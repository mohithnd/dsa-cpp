#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Approach: Place the first cow in the first stall.
// Place each remaining cow in the earliest stall at least dis away
// from the last placed cow. This leaves maximum room for later cows.
// Return true if all k cows can be placed.
// Requires sorted stall positions.
//
// Time complexity: O(n) worst case.
// Auxiliary space: O(1).
bool check(vector<int> &arr, int k, int dis)
{
    int last_ind = 0;
    k--;
    for (int i = 1; i < arr.size(); i++)
    {
        int curr_dis = arr[i] - arr[last_ind];
        if (curr_dis >= dis)
        {
            k--;
            last_ind = i;
            if (k <= 0)
            {
                return true;
            }
        }
    }
    return k <= 0;
}

// Approach: Sort the stalls, then try every minimum distance
// from 1 to the distance between the first and last stalls.
// Keep the largest distance that allows all k cows to be placed.
//
// Let D = largest stall position - smallest stall position.
// Time complexity: O(n log n + n * D), including sorting.
// Auxiliary space: O(log n) for typical std::sort implementations;
// the distance-search logic itself uses O(1).
int aggressive_cows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int s = 1;
    int e = arr[arr.size() - 1] - arr[0];
    int ans = -1;

    for (int i = s; i <= e; i++)
    {
        if (check(arr, k, i))
        {
            ans = i;
        }
    }

    return ans;
}

// Approach: Sort the stalls and binary-search the minimum distance.
// If a distance works, save it and try larger distances.
// If it fails, try smaller distances.
// This works because increasing the required distance makes placement
// harder: once a distance fails, every larger distance also fails.
//
// Let D = largest stall position - smallest stall position.
// Time complexity: O(n log n + n * log(D + 1)), including sorting.
// Auxiliary space: O(log n) for typical std::sort implementations;
// the distance-search logic itself uses O(1).
int aggressive_cows_2(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int s = 1;
    int e = arr[arr.size() - 1] - arr[0];
    int ans = -1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (check(arr, k, m))
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 8, 9};
    int k = 3;

    vector<int> arr2 = {10, 1, 2, 7, 5};
    int k2 = 3;

    cout << aggressive_cows(arr, k) << endl;
    cout << aggressive_cows(arr2, k2) << endl;

    cout << endl;

    cout << aggressive_cows_2(arr, k) << endl;
    cout << aggressive_cows_2(arr2, k2) << endl;

    return 0;
}