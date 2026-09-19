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

// Approach: Scan from the beginning to find the first occurrence.
// Then scan from the end to find the last occurrence.
// If the target is absent, return {-1, -1}.
// Works on both sorted and unsorted arrays.
//
// Time complexity: O(n) worst case — two linear scans.
// Auxiliary space: O(1) — only a few variables and a fixed-size result.
vector<int> first_and_last_position(vector<int> &arr, int target)
{
    vector<int> ans = {-1, -1};

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            ans[0] = i;
            break;
        }
    }

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] == target)
        {
            ans[1] = i;
            break;
        }
    }

    return ans;
}

// Approach: Use two binary searches on an ascending sorted array.
// First occurrence: Save a matching index and continue searching left.
// Last occurrence: Save a matching index and continue searching right.
// If the target is absent, return {-1, -1}.
//
// Time complexity: O(log n) — two binary searches.
// Auxiliary space: O(1) — only a few variables and a fixed-size result.
vector<int> first_and_last_position_2(vector<int> &arr, int target)
{
    vector<int> ans = {-1, -1};

    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == target)
        {
            ans[0] = m;
            e = m - 1;
        }
        else if (target > arr[m])
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }

    s = 0;
    e = arr.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == target)
        {
            ans[1] = m;
            s = m + 1;
        }
        else if (target < arr[m])
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    vector<int> arr2 = {1, 2, 3};

    vectorPrint(first_and_last_position(arr1, 5));
    vectorPrint(first_and_last_position(arr2, 5));

    cout << endl;

    vectorPrint(first_and_last_position_2(arr1, 5));
    vectorPrint(first_and_last_position_2(arr2, 5));

    return 0;
}