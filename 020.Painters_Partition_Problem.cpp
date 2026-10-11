#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void vectorPrint(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << "  ";
    }
    cout << endl;
}

// Approach: Assign consecutive boards to the current painter
// while their total length stays within limit.
// If the next board exceeds the limit, assign it to a new painter.
// The limit is feasible if at most k painters are needed.
//
// Assumption: limit >= the largest board length.
// Time complexity: O(n).
// Auxiliary space: O(1).
bool check(vector<int> &arr, int k, long long limit)
{
    int painters = 1;
    long long total = 0;

    for (int i : arr)
    {
        if (i + total <= limit)
        {
            total += i;
        }
        else
        {
            painters++;
            total = i;
        }
    }

    return painters <= k;
}

// Approach: Try every time limit from the largest board length
// to the sum of all board lengths.
// Return the first feasible limit, which is the minimum time.
//
// Let R = sum of lengths - largest length + 1.
// Time complexity: O(n * R).
// Auxiliary space: O(1).
long long painter_partition(vector<int> &arr, int k)
{
    long long start = 0;
    long long end = 0;

    for (int i : arr)
    {
        end += i;
        if (i > start)
        {
            start = i;
        }
    }

    for (long long i = start; i <= end; i++)
    {
        if (check(arr, k, i))
        {
            return i;
        }
    }

    return -1;
}

// Approach: Binary-search the time limit between the largest
// board length and the sum of all board lengths.
// If a limit works, save it and search for a smaller limit.
// Otherwise, increase the limit.
//
// Let R = sum of lengths - largest length + 1.
// Time complexity: O(n * log(R + 1)).
// Auxiliary space: O(1).
long long painter_partition_2(vector<int> &arr, int k)
{
    long long start = 0;
    long long end = 0;

    for (int i : arr)
    {
        end += i;
        if (i > start)
        {
            start = i;
        }
    }

    long long ans = -1;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        if (check(arr, k, mid))
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
    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;

    vector<int> arr2 = {10, 20, 30, 40};
    int k2 = 2;

    cout << painter_partition(arr, k) << endl;
    cout << painter_partition(arr2, k2) << endl;

    cout << endl;

    cout << painter_partition_2(arr, k) << endl;
    cout << painter_partition_2(arr2, k2) << endl;

    return 0;
}