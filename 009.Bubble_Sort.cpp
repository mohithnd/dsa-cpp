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

// Approach: Compare adjacent elements and swap them if they are
// in the wrong order. Each pass moves the largest remaining element
// to the end of the unsorted portion.
// If a pass makes no swaps, the array is sorted, so stop early.
//
// Time complexity:
// Best case: O(n) — an already sorted array needs only one pass.
// Average and worst cases: O(n²) — repeated comparisons and swaps.
//
// Auxiliary space: O(1) — sorts in place using a few variables.
void bubble_sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {
        bool swapped = false;

        for (int j = 1; j <= i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swapped = true;
                swap(arr[j], arr[j - 1]);
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr = {7, 2, 89, -3, 24, 9};

    vectorPrint(arr);

    bubble_sort(arr);

    vectorPrint(arr);

    return 0;
}