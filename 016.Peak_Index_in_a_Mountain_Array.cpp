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

// Approach: Scan the array and track the index of the largest element.
// In a mountain array, the largest element is the peak.
//
// Time complexity: O(n).
// Auxiliary space: O(1).
int peak_index_in_mountain_array(vector<int> &arr)
{
    if (arr.empty())
    {
        return -1;
    }

    int ans = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[ans])
        {
            ans = i;
        }
    }

    return ans;
}

// Approach: Check the endpoints first, then binary-search the interior.
// If the middle element exceeds both neighbours, it is a peak.
// Otherwise, move toward the larger neighbour:
// a peak must exist in that direction.
//
// Assumption: Adjacent elements are unequal.
// Works for mountain arrays and general arrays under this assumption.
// For general arrays, returns any peak, not necessarily the maximum.
//
// Time complexity: O(log n) worst case; O(1) for endpoint returns.
// Auxiliary space: O(1).
int peak_index_in_mountain_array_2(vector<int> &arr)
{
    int n = arr.size();

    if (n == 0)
    {
        return -1;
    }

    if (n == 1)
    {
        return 0;
    }

    if (arr[0] > arr[1])
    {
        return 0;
    }

    if (arr[n - 1] > arr[n - 2])
    {
        return n - 1;
    }

    int s = 1;
    int e = n - 2;

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1])
        {
            return m;
        }

        if (arr[m] > arr[m - 1])
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {0, 1, 0};
    vector<int> brr = {0, 2, 1, 0};
    vector<int> crr = {0, 10, 5, 2};

    cout << peak_index_in_mountain_array(arr) << endl;
    cout << peak_index_in_mountain_array(brr) << endl;
    cout << peak_index_in_mountain_array(crr) << endl;
    cout << endl;

    cout << peak_index_in_mountain_array_2(arr) << endl;
    cout << peak_index_in_mountain_array_2(brr) << endl;
    cout << peak_index_in_mountain_array_2(crr) << endl;
    cout << endl;
    return 0;
}