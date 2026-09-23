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

// Approach: Scan every element and count matches with the target.
// Works on both sorted and unsorted arrays.
//
// Time complexity: O(n) — always scans the entire array.
// Auxiliary space: O(1) — uses only a counter and loop variable.
int number_of_occurrence(vector<int> &arr, int target)
{
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            ans++;
        }
    }

    return ans;
}

// Approach: Scan from the beginning to find the first occurrence,
// then scan from the end to find the last occurrence.
// In a sorted array, all occurrences are consecutive,
// so count = last - first + 1. Return 0 if the target is absent.
//
// Time complexity: O(n) worst case — two linear scans.
// Auxiliary space: O(1).
int number_of_occurrence_2(vector<int> &arr, int target)
{
    int n = arr.size();
    int first = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            first = i;
            break;
        }
    }

    int last = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == target)
        {
            last = i;
            break;
        }
    }

    if (first == -1 || last == -1)
    {
        return 0;
    }

    return last - first + 1;
}

// Approach: Use two binary searches on an ascending sorted array.
// First occurrence: Save a matching index and continue searching left.
// Last occurrence: Save a matching index and continue searching right.
// Return last - first + 1, or 0 if the target is absent.
//
// Time complexity: O(log n) — two binary searches.
// Auxiliary space: O(1) — both searches are iterative.
int number_of_occurrence_3(vector<int> &arr, int target)
{
    int n = arr.size();
    int first = -1;
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] == target)
        {
            first = m;
            e = m - 1;
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

    int last = -1;
    s = 0;
    e = n - 1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] == target)
        {
            last = m;
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

    if (first == -1 || last == -1)
    {
        return 0;
    }

    return last - first + 1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    vector<int> brr = {8, 9, 10, 12, 12, 12};

    cout << number_of_occurrence(arr, 2) << endl;
    cout << number_of_occurrence(arr, 4) << endl;
    cout << number_of_occurrence(brr, 12) << endl;
    cout << endl;

    cout << number_of_occurrence_2(arr, 2) << endl;
    cout << number_of_occurrence_2(arr, 4) << endl;
    cout << number_of_occurrence_2(brr, 12) << endl;
    cout << endl;

    cout << number_of_occurrence_3(arr, 2) << endl;
    cout << number_of_occurrence_3(arr, 4) << endl;
    cout << number_of_occurrence_3(brr, 12) << endl;
    cout << endl;

    return 0;
}