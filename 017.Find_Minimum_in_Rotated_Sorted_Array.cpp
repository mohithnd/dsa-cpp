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

// Approach: Scan every element and track the smallest value.
// Works on any non-empty array, including arrays with duplicates.
//
// Time complexity: O(n).
// Auxiliary space: O(1).
int findMinInSortedRotatedArray(vector<int> &arr)
{
    int ans = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < ans)
        {
            ans = arr[i];
        }
    }

    return ans;
}

// Approach: Use the first element to distinguish the two sorted parts.
// If arr[m] >= arr[0], search right for the smaller, rotated part.
// Otherwise, save arr[m] and search left for an earlier, smaller value.
// If the array is not rotated, arr[0] remains the answer.
//
// Requires a non-empty rotated sorted array with distinct elements.
//
// Time complexity: O(log n) — halves the search range each step.
// Auxiliary space: O(1).
int findMinInSortedRotatedArray_2(vector<int> &arr)
{
    int n = arr.size();
    int ans = arr[0];

    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] >= arr[0])
        {
            s = m + 1;
        }
        else
        {
            ans = arr[m];
            e = m - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    vector<int> brr = {4, 5, 6, 7, 0, 1, 2};
    vector<int> crr = {11, 13, 15, 17};

    cout << findMinInSortedRotatedArray(arr) << endl;
    cout << findMinInSortedRotatedArray(brr) << endl;
    cout << findMinInSortedRotatedArray(crr) << endl;
    cout << endl;

    cout << findMinInSortedRotatedArray_2(arr) << endl;
    cout << findMinInSortedRotatedArray_2(brr) << endl;
    cout << findMinInSortedRotatedArray_2(crr) << endl;
    cout << endl;
    return 0;
}