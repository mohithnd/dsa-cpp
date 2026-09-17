#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void vectorPrint(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << "  ";
    }
    cout << endl;
}

// Approach: Compare the target with the middle element.
// If smaller, search the left half; if larger, search the right half.
// Repeat until the target is found or the search range becomes empty.
// Requires the array to be sorted in ascending order.
//
// Time complexity:
// Best case: O(1) — the first middle element matches.
// Average and worst cases: O(log n) — halves the search range each step.
//
// Auxiliary space: O(1) — uses only a few variables.
void binary_search(vector<int> &arr, int target)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (arr[m] == target)
        {
            cout << "Found" << endl;
            return;
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

    cout << "Not Found" << endl;
}

int main()
{
    vector<int> arr = {-3, 2, 7, 9, 24, 89};

    binary_search(arr, 2);
    binary_search(arr, 20);

    return 0;
}