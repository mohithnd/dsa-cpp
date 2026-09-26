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

// Approach: Scan every element and return the index matching the target.
// Return -1 if the target is absent.
//
// Time complexity: O(n) worst case; O(1) best case.
// Auxiliary space: O(1).
int search_in_rotated_sorted_array(vector<int> &arr, int taregt)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == taregt)
        {
            return i;
        }
    }
    return -1;
}

// Approach: Find the index of the minimum element using binary search.
// Values >= arr[0] belong to the first sorted part, so search right.
// Otherwise, save the index and search left for the start of the
// second sorted part. If there is no rotation, return index 0.
//
// Requires distinct elements.
// Time complexity: O(log n).
// Auxiliary space: O(1).
int find_pivot(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int ans = 0;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] >= arr[0])
        {
            s = m + 1;
        }
        else
        {
            ans = m;
            e = m - 1;
        }
    }
    return ans;
}

// Approach: Compare the target with the middle element of a sorted range.
// Search left if the target is smaller; otherwise, search right.
// Return -1 if the search range becomes empty.
//
// Time complexity: O(log n) worst case; O(1) best case.
// Auxiliary space: O(1).
int binarySearch(vector<int> &arr, int s, int e, int target)
{
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == target)
        {
            return m;
        }
        if (target < arr[m])
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return -1;
}

// Approach: Find the pivot to split the array into two sorted ranges.
// Binary-search the first range. If the target is absent there,
// binary-search the second range.
//
// Time complexity: O(log n) — pivot search plus up to two binary searches.
// Auxiliary space: O(1).
int search_in_rotated_sorted_array_2(vector<int> &arr, int taregt)
{
    int pivot = find_pivot(arr);

    int ans1 = binarySearch(arr, 0, pivot - 1, taregt);
    if (ans1 != -1)
    {
        return ans1;
    }
    int ans2 = binarySearch(arr, pivot, arr.size() - 1, taregt);
    return ans2;
}

// Approach: Search directly using modified binary search.
// Compare arr[m] with arr[0] to identify which sorted part contains m.
// If m is in the first part, check whether the target fits to its left.
// Otherwise, check whether the target fits in the sorted range to its right.
// Keep the appropriate half until the target is found or the range is empty.
//
// Requires distinct elements.
// Time complexity: O(log n) worst case; O(1) best case.
// Auxiliary space: O(1).
int search_in_rotated_sorted_array_3(vector<int> &arr, int taregt)
{
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == taregt)
        {
            return m;
        }
        if (arr[m] >= arr[0])
        {
            if (taregt >= arr[0] && taregt < arr[m])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        else
        {
            if (taregt > arr[m] && taregt <= arr[e])
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    vector<int> brr = {1};
    int a = 0;
    int b = 3;
    int c = 0;

    cout << search_in_rotated_sorted_array(arr, a) << endl;
    cout << search_in_rotated_sorted_array(arr, b) << endl;
    cout << search_in_rotated_sorted_array(brr, c) << endl;
    cout << endl;

    cout << search_in_rotated_sorted_array_2(arr, a) << endl;
    cout << search_in_rotated_sorted_array_2(arr, b) << endl;
    cout << search_in_rotated_sorted_array_2(brr, c) << endl;
    cout << endl;

    cout << search_in_rotated_sorted_array_3(arr, a) << endl;
    cout << search_in_rotated_sorted_array_3(arr, b) << endl;
    cout << search_in_rotated_sorted_array_3(brr, c) << endl;
    cout << endl;

    return 0;
}